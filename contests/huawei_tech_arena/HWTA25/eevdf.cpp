#include <bits/stdc++.h>
using namespace std;

struct UAV {
    int idx;
    int x, y;
    double B;
    int phi;
};

struct Flow {
    int idx;
    int f;
    int x, y;
    int t_start;
    double Q_total;
    int m1, n1, m2, n2;
    double remaining_Q;
};

double get_bw(double B, int phi, int t) {
    int t_adj = (t + phi) % 10;
    if (t_adj == 0 || t_adj == 1 || t_adj == 8 || t_adj == 9) {
        return 0.0; 
    }
    if (t_adj == 2 || t_adj == 7) {
        return B / 2.0;
    }
    // Time slots 3, 4, 5, 6
    return B; 
}


int manhattan_dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    int M, N, FN, T;
    cin >> M >> N >> FN >> T;

    vector<UAV> uavs(M * N);
    map<pair<int, int>, int> coord_to_uav_idx;
    for (int i = 0; i < M * N; ++i) {
        uavs[i].idx = i;
        cin >> uavs[i].x >> uavs[i].y >> uavs[i].B >> uavs[i].phi;
        coord_to_uav_idx[{uavs[i].x, uavs[i].y}] = i;
    }

    vector<Flow> flows(FN);
    for (int i = 0; i < FN; ++i) {
        flows[i].idx = i;
        cin >> flows[i].f >> flows[i].x >> flows[i].y >> flows[i].t_start 
            >> flows[i].Q_total >> flows[i].m1 >> flows[i].n1 >> flows[i].m2 >> flows[i].n2;
        flows[i].remaining_Q = flows[i].Q_total;
    }

    vector<vector<double>> bw_cache(M * N, vector<double>(T));
    for (int i = 0; i < M * N; ++i) {
        for (int t = 0; t < T; ++t) {
            bw_cache[i][t] = get_bw(uavs[i].B, uavs[i].phi, t);
        }
    }

    vector<vector<double>> remaining_bw = bw_cache;

    vector<vector<int>> landing_UAVs_for_flow(FN);
    for (int i = 0; i < FN; ++i) {
        for (int x = flows[i].m1; x <= flows[i].m2; ++x) {
            for (int y = flows[i].n1; y <= flows[i].n2; ++y) {
                if (coord_to_uav_idx.count({x, y})) {
                    landing_UAVs_for_flow[i].push_back(coord_to_uav_idx[{x, y}]);
                }
            }
        }
    }

    const double ALPHA = 0.1;
    vector<vector<double>> dist_score_cache(FN, vector<double>(M * N));
    for (int i = 0; i < FN; ++i) {
        for (int u_idx : landing_UAVs_for_flow[i]) {
            int dist = manhattan_dist(flows[i].x, flows[i].y, uavs[u_idx].x, uavs[u_idx].y);
            dist_score_cache[i][u_idx] = pow(2.0, -ALPHA * dist); 
        }
    }

    vector<set<int>> used_UAVs_by_flow(FN);
    vector<vector<tuple<int, int, int, double>>> flow_schedules(FN);

    for (int t = 0; t < T; ++t) {
        vector<int> active_flow_indices;
        for (int i = 0; i < FN; ++i)
            if (t >= flows[i].t_start && flows[i].remaining_Q > 1e-9)
                active_flow_indices.push_back(i);

        sort(active_flow_indices.begin(), active_flow_indices.end(), [&](int a, int b) {return flows[a].remaining_Q > flows[b].remaining_Q;});

        for (int f_idx : active_flow_indices) {
            Flow& f = flows[f_idx];
            double demand = f.remaining_Q;

            vector<pair<double, int>> uav_candidates;
            for (int u_idx : landing_UAVs_for_flow[f_idx]) {
                if (remaining_bw[u_idx][t] > 1e-9) {
                    double dist_score_comp = 0.3 * dist_score_cache[f_idx][u_idx]; 
                    
                    double land_bonus = 0.0;
                    int k = used_UAVs_by_flow[f_idx].size();
                    bool is_new = (used_UAVs_by_flow[f_idx].find(u_idx) == used_UAVs_by_flow[f_idx].end());

                    if (k == 0) 
                        land_bonus = 100.0; // bonus fuerte  para k=1
                    else if (!is_new)
                        land_bonus = 50.0; // bonuz medio para re-usar UAV existente
                    
                    double priority = dist_score_comp + land_bonus;
                    uav_candidates.push_back({priority, u_idx});
                }
            }

            sort(uav_candidates.rbegin(), uav_candidates.rend());

            for (auto& cand : uav_candidates) {
                if (demand < 1e-9) break; 

                int u_idx = cand.second;
                double avail_bw = remaining_bw[u_idx][t];
                double alloc = min(demand, avail_bw);

                if (alloc > 1e-9) {
                    UAV& u = uavs[u_idx];
                    flow_schedules[f_idx].push_back(make_tuple(t, u.x, u.y, alloc)); 

                    f.remaining_Q -= alloc;
                    remaining_bw[u_idx][t] -= alloc;
                    demand -= alloc;
                    used_UAVs_by_flow[f_idx].insert(u_idx); 
                }
            }
        }
    }

    for (int i = 0; i < FN; ++i) {
        cout << flows[i].f << " " << flow_schedules[i].size() << "\n"; 
        for (const auto& record : flow_schedules[i])
            cout << get<0>(record) << " " << get<1>(record) << " " << get<2>(record) << " " << get<3>(record) << "\n"; 
    }
}
