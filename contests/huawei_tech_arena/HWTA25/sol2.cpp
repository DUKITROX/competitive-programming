#include <bits/stdc++.h>
using namespace std;

struct UAV {
    int x, y;
    int phi;
    double B,b;
};

struct Flow {
    int id;
    int m1, n1, m2, n2;
    int access_x, access_y;
    int last_x, last_y;
    int t_0;
    double Q,q;
    int k;
    vector<tuple<int, int, int, double>> schedule;
};

double metric(double Q, double q, int d, int t, int k) {
    double s1 = q/Q;
    double s2 = (10.0 * q) / ((t + 10.0)*Q);
    double s3 = q / (pow(2.0, 0.1 * d)*Q);
    double s4 = 1.0 / max(1.0, (double)k); 
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
        if (abs(ratio - other.ratio) > 200.0) {
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
vector<vector<double>> prefix_B;

struct State {
    int t_i; 
    double cost;
    double cost_h; // cost + heuristic

    vector<vector<UAV>> uavs; 
    vector<Flow> flows; 
    vector<TransmissionRequest> requests;

    bool operator <(const State& other) const {
        return cost_h > other.cost_h; 
    }
};

double get_B(int m1, int n1, int m2, int n2) {
    return prefix_B[m2 + 1][n2 + 1] 
         - prefix_B[m1][n2 + 1] 
         - prefix_B[m2 + 1][n1] 
         + prefix_B[m1][n1];
}

void solve(State& state) { // O(FN.M.N)
    for (int t = state.t_i; t < T; t++){
        vector<vector<UAV>>& uavs = state.uavs;
        vector<Flow>& flows = state.flows;

        vector<vector<double>> available_bw(M, vector<double>(N, 0.0));
        vector<vector<double>> demand(M, vector<double>(N, 0.0));
        vector<double> supply(FN, 0.0);

        int mode = 1; // 0 := normal, 1 := linear prediction, 2 := e prediction
        double temperature = 0.9;

        // available bandwidth
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                available_bw[i][j] = (t == state.t_i ? uavs[i][j].b : get_bandwidth(uavs[i][j], t));
            }
        }

        // process demand & supply
        for (int i = 0; i < FN; i++) {
            if (flows[i].q > 1e-9) {
			    for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) {
				    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) {
                        if(flows[i].t_0 <= t){
                            demand[lx][ly] += flows[i].q;
                            supply[i] += available_bw[lx][ly];
                        }else{
                            if(mode == 1){
                                demand[lx][ly] += (flows[i].q * (T-flows[i].t_0))/(T-t); 
                                supply[i] += (uavs[lx][ly].B/2.0) * ((T-flows[i].t_0) / (T-t));
                            }else if(mode == 2){
                                demand[lx][ly] += flows[i].q * exp((t - flows[i].t_0)/temperature) * (T-flows[i].t_0)/(T-t);
                                supply[i] += (uavs[lx][ly].B/2) * ((T - flows[i].t_0)/(T-t)) * ((-t*exp((t - flows[i].t_0)/temperature))/T + t/flows[i].t_0);
                            }
                        }
				    }
				}
			}
        }

        vector<TransmissionRequest> requests;

        // process each possivle flow transmission
        for (int i = 0; i < FN; i++) {
            if (flows[i].t_0 <= t && flows[i].q > 1e-9) {
                for (int lx = flows[i].m1; lx <= flows[i].m2; lx++) {
                    for (int ly = flows[i].n1; ly <= flows[i].n2; ly++) {
                        if (available_bw[lx][ly] > 1e-9) {

                            int dist = manhattan_distance(flows[i].access_x, flows[i].access_y, lx, ly);
                            int potential_k = flows[i].k + !(flows[i].last_x == lx && flows[i].last_y == ly);
                            double ratio = demand[lx][ly] / supply[i];

                            requests.push_back({i, lx, ly, dist, flows[i].Q, flows[i].q, ratio, potential_k, t});
                        }
                    }
                }
            }
        }
        
        sort(requests.begin(), requests.end());
        
		set<int> s;
        for (const auto& req : requests) {
            int flow_idx = req.flow_idx;
            int uav_x = req.uav_x;
            int uav_y = req.uav_y;
            
            if (flows[flow_idx].q > 1e-9 && available_bw[uav_x][uav_y] > 1e-9 && !s.count(flow_idx)) {
                double amount_to_send = min(flows[flow_idx].q, available_bw[uav_x][uav_y]);
				s.insert(flow_idx);
                
                flows[flow_idx].q -= amount_to_send;
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
    State s0 = {0,0.0,100.0};
    s0.uavs.resize(M, vector<UAV>(N));
    s0.flows.resize(FN);

    for (int i = 0; i < M * N; ++i) {
        int x, y, phi;
        double B;
        cin >> x >> y >> B >> phi;
        s0.uavs[x][y] = {x, y, phi, B, 0.0};
        s0.uavs[x][y].b = get_bandwidth(s0.uavs[x][y], 0);
    }

    for (int i = 0; i < FN; ++i) {
        int id, ax, ay, ts, m1, n1, m2, n2;
        double qt;
        cin >> id >> ax >> ay >> ts >> qt >> m1 >> n1 >> m2 >> n2;
        s0.flows[i] = {id, m1, n1, m2, n2, ax, ay, -1, -1, ts, qt, qt, 0};
    }

    solve(s0);

    cout << fixed << setprecision(5);
    for (const auto& flow : s0.flows) {
        cout << flow.id << " " << flow.schedule.size() << "\n";
        for (const auto& record : flow.schedule) {
            cout << get<0>(record) << " " << get<1>(record) << " " << get<2>(record) << " " << get<3>(record) << "\n";
        }
    }
}
