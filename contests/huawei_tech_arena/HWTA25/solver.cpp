#include <bits/stdc++.h>
using namespace std;

struct UAV {
    int x, y;
    int phi;
    double B;
};

struct Flow {
    int id;
    int access_x, access_y;
    int last_x, last_y;
    int t_start;
    double Q_total;
    int m1, n1, m2, n2;
    double remaining_Q;
    double total_peak_bw;
    int k;
    vector<tuple<int, int, int, double>> schedule;
};

double metric(double Q, double q, int d, int t, int k) {
    double s1 = q;
    double s2 = (10.0 * q) / ((t + 10.0));
    double s3 = q / (pow(2.0, 0.1 * d) );
    double s4 = Q / max(1.0, (double)k); 
    return 0.4*s1 + 0.2*s2 + 0.3*s3 + 0.1*s4;
}

struct TransmissionRequest {
    int flow_idx;
    int uav_x, uav_y;
    int distance;
    double Q, q;
    double ratio;
    int k, time;

    bool operator<(const TransmissionRequest& other) const {
        if (abs(ratio - other.ratio) > 23.0) {
            return ratio > other.ratio; 
        }
        return metric(Q, q, distance, time, k) > metric(other.Q, other.q, other.distance, other.time, other.k);
    }
};

double get_bandwidth(const UAV& uav, int t) {
    int effective_time = (t + uav.phi) % 10;
    if (effective_time <= 1 || effective_time >= 8) return 0.0;
    if (effective_time == 2 || effective_time == 7) return uav.B / 2.0;
    return uav.B;
}

int manhattan_distance(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int M, N, FN, T;
vector<vector<UAV>> uavs;
vector<Flow> flows;
vector<vector<double>> peak_B_prefix_sum;

double get_peak_bw_sum(int m1, int n1, int m2, int n2) {
    return peak_B_prefix_sum[m2 + 1][n2 + 1] 
         - peak_B_prefix_sum[m1][n2 + 1] 
         - peak_B_prefix_sum[m2 + 1][n1] 
         + peak_B_prefix_sum[m1][n1];
}

void solve() {
    for (int t = 0; t < T; ++t) {
        vector<vector<double>> available_bw(M, vector<double>(N, 0.0));
        vector<vector<double>> demand(M, vector<double>(N, 0.0));
        vector<double> supply(FN, 0.0);

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                available_bw[i][j] = get_bandwidth(uavs[i][j], t);
            }
        }
        
        for (int i = 0; i < FN; ++i) {
            if (flows[i].remaining_Q > 1e-9) { 
			    for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) {
				    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) {
                        if(flows[i].t_start <= t){ // flow started
                            demand[lx][ly] += flows[i].remaining_Q;
                            supply[i] += available_bw[lx][ly];
                            //supply[i] += available_bw[lx][ly]*0.75 + uavs[lx][ly].B*0.25;
                        }else{ // flow yet to start
                            demand[lx][ly] += ((T-flows[i].t_start) * flows[i].remaining_Q)/(T-t);
                            double r = -0.95;
                            //demand[lx][ly] += flows[i].remaining_Q*(log(1 + (r*(T-flows[i].t_start)) / (T-t)) / log(1+0.98));
                        }
				    }
				}
			}
        }

        vector<TransmissionRequest> requests;
        for (int i = 0; i < FN; ++i) {
            if (flows[i].t_start <= t && flows[i].remaining_Q > 1e-9) {
                for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) {
                    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) {
                        if (available_bw[lx][ly] > 1e-9) {
                            int dist = manhattan_distance(flows[i].access_x, flows[i].access_y, lx, ly);
                            int potential_k = !flows[i].k ? 1 : flows[i].k + !(flows[i].last_x == lx && flows[i].last_y == ly);
                            double ratio = demand[lx][ly] / supply[i];

                            requests.push_back({i, lx, ly, dist, flows[i].Q_total, flows[i].remaining_Q, ratio, potential_k, t});
                        }
                    }
                }
            }
        }
        
        sort(requests.begin(), requests.end());
        
        for (const auto& req : requests) {
            int flow_idx = req.flow_idx;
            int uav_x = req.uav_x;
            int uav_y = req.uav_y;
            
            if (flows[flow_idx].remaining_Q > 1e-9 && available_bw[uav_x][uav_y] > 1e-9) {
                double amount_to_send = min(flows[flow_idx].remaining_Q, available_bw[uav_x][uav_y]);
                
                flows[flow_idx].remaining_Q -= amount_to_send;
                available_bw[uav_x][uav_y] -= amount_to_send;

                flows[flow_idx].k += !(flows[flow_idx].last_x == uav_x && flows[flow_idx].last_y == uav_y);
                flows[flow_idx].last_x = uav_x;
                flows[flow_idx].last_y = uav_y;

                flows[flow_idx].schedule.push_back(make_tuple(t, uav_x, uav_y, amount_to_send));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> M >> N >> FN >> T;

    uavs.resize(M, vector<UAV>(N));
    flows.resize(FN);
    peak_B_prefix_sum.resize(M + 1, vector<double>(N + 1, 0.0));

    for (int i = 0; i < M * N; ++i) {
        int x, y, phi;
        double B;
        cin >> x >> y >> B >> phi;
        uavs[x][y] = {x, y, phi, B};
    }

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            peak_B_prefix_sum[i + 1][j + 1] = uavs[i][j].B + peak_B_prefix_sum[i][j + 1] + peak_B_prefix_sum[i + 1][j] - peak_B_prefix_sum[i][j];

    for (int i = 0; i < FN; ++i) {
        int id, ax, ay, ts, m1, n1, m2, n2;
        double qt;
        cin >> id >> ax >> ay >> ts >> qt >> m1 >> n1 >> m2 >> n2;
        
        double total_bw = get_peak_bw_sum(m1, n1, m2, n2);
        
        flows[i] = {id, ax, ay, -1, -1, ts, qt, m1, n1, m2, n2, qt, total_bw, 0};
    }

    solve();

    cout << fixed << setprecision(5);
    for (const auto& flow : flows) {
        cout << flow.id << " " << flow.schedule.size() << "\n";
        for (const auto& record : flow.schedule) {
            cout << get<0>(record) << " " << get<1>(record) << " " << get<2>(record) << " " << get<3>(record) << "\n";
        }
    }
}
