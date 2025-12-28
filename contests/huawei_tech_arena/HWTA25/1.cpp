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
	int area,k;

    vector<tuple<int, int, int, double>> schedule; // outputted data, used for output
};

int M, N, FN, T;
vector<vector<UAV>> uavs;
vector<Flow> flows;

double metric(int Q, double q, int d, int t, int k){
	double s1 = q/Q;
	double s2 = (10*q) / ((t + 10)*Q);
	double s3 = q / (Q*pow(2,0.1*d));
	double s4 = 1.0/k;
	return s1*0.4 + s2*0.2 + s3*0.3 + s4*0.1;
}

struct TransmissionRequest {
    int flow_idx;
    int uav_x, uav_y;
    int distance;
	double Q,q;
	double ratio;
	int k,time;

    bool operator<(const TransmissionRequest& other) const {
		/*
		if(abs(ratio - other.ratio) > 2.1) return ratio > other.ratio;
		return metric(Q, q, distance, time, k) > metric(other.Q, other.q, other.distance, other.time, k);
		if(changes ^ other.changes){
			return changes < other.changes;
		}
        if (abs(quantity - other.quantity) > 1e-6){
            return quantity > other.quantity;
        }
        */
/*
        if (abs(distance - other.distance) != 0) {
            return distance < other.distance;
        }*/
        return flow_idx < other.flow_idx;
    }
};

double get_bandwidth(const UAV& uav, int t) {
    int effective_time = (t + uav.phi) % 10;
    if (effective_time <= 1 || effective_time >= 8) {
        return 0.0;
    } else if (effective_time == 2 || effective_time == 7) {
        return uav.B / 2.0;
    } else { // 3, 4, 5, 6
        return uav.B;
    }
}

int manhattan_distance(int x1, int y1, int x2, int y2) {return abs(x1 - x2) + abs(y1 - y2);}

void solve() {
    for (int t = 0; t < T; ++t) {
        vector<vector<double>> available_bw(M, vector<double>(N, 0.0));
		vector<vector<int>> popu(M, vector<int>(N,0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                available_bw[i][j] = get_bandwidth(uavs[i][j], t);
            }
        }
        for (int i = 0; i < FN; ++i) 
            if (flows[i].t_start <= t && flows[i].remaining_Q > 1e-9) 
                for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) 
                    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) 
                        if (available_bw[lx][ly] > 1e-9)
							popu[lx][ly]++;

        vector<TransmissionRequest> requests;
        for (int i = 0; i < FN; ++i) {
            if (flows[i].t_start <= t && flows[i].remaining_Q > 1e-9) {
                for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) {
                    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) {
                        if (available_bw[lx][ly] > 1e-9) {
                            int dist = manhattan_distance(flows[i].access_x, flows[i].access_y, lx, ly);
                            requests.push_back({i, lx, ly, dist, flows[i].Q_total, flows[i].remaining_Q, (double)popu[lx][ly]/flows[i].area,
								flows[i].k + !(flows[i].last_x == lx && flows[i].last_y == ly), t});
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

    for (int i = 0; i < M * N; ++i) {
        int x, y, phi;
        double B;
        cin >> x >> y >> B >> phi;
        uavs[x][y] = {x, y, phi, B};
    }

    for (int i = 0; i < FN; ++i) {
        int id, ax, ay, ts, m1, n1, m2, n2;
        double qt;
        cin >> id >> ax >> ay >> ts >> qt >> m1 >> n1 >> m2 >> n2;
        flows[i] = {id, ax, ay, -1, -1,ts, qt, m1, n1, m2, n2, qt, (m2-m1+1)*(n2-n1+1),0};
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
