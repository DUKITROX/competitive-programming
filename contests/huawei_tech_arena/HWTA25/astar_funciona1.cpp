#include <iostream>
#include <string>
#include <vector> 
#include <iomanip>
#include <queue>
#include <climits>
#include <tuple>
#include <algorithm>
#include <list>
using namespace std;
const int MAX_SIZE = 20; 
const double BOOST_FACTOR = 1.05; 
const double BOOST_ADD = 0.0; 

struct UAV {
    int x, y;
    int phi;
    double B;
    double band_width; 
};

struct Flow {
    int id;
    int access_x, access_y;
    int t_start;
    double Q_total;
    int m1, n1, m2, n2;
    double remaining_Q;
    int k; 
    int iLastDrone = -1; 
    int jLastDrone=-1; 
    double score; 
    vector<tuple<int, int, int, double>> schedule; // outputted data, used for output
};

struct TransmissionRequest {
    int flow_idx;
    int uav_x, uav_y;
    int distance;

    bool operator<(const TransmissionRequest& other) const {
        if (distance != other.distance) {
            return distance < other.distance;
        }
        return flow_idx < other.flow_idx;
    }
};

struct Estado {
    vector<Flow> flows; 
    vector<vector<UAV>> uavs; 
    int t; 
    double costeAcum;
    double f; // score que llevas
    bool operator <(const Estado& other) const {
        return f < other.f; 
    }
};

int M, N, FN, T;
double QT; 
vector<Flow> flows;
double EPS = 0.000001; 

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

double get_max_bandwidth(const Estado& e,const Flow& f, int t) {
    double maxi = 0;
    for (int x = f.m1; x <= f.m2; ++x) {
        for (int y = f.n1; y <= f.n2; ++y) {
            maxi = max(maxi, e.uavs[x ][y ].band_width); 
        }
    }
    return maxi; 
}
//Calcular la menor dist a un uav de la zona: 


void calcHeuristicF(Estado& e, const Flow  & f) {
    double S = 0;
    double quedan = f.remaining_Q; 
    for (int i = e.t; i <= T && quedan > 0; ++i) {
        double b = get_max_bandwidth(e, f, i); 
        double q = min(b, quedan); 
        double ratio = q / f.Q_total; 
        //Primera m�trica 
        S += 0.4*ratio; 
        quedan = quedan - q; 
        //Segunda 
        S += 0.2*(10 / double((i + 10))) * ratio; 
        //Tercera: 
        double dist = (f.access_x <= f.m2 && f.access_x >= f.m1 ? 0 : min(abs(f.access_x - f.m1), abs(f.access_x - f.m2))) + (f.access_y <= f.n2 && f.access_x >= f.n1 ? 0 : min(abs(f.access_y - f.n1), abs(f.access_x - f.n2))); 
        S += 0.3*ratio * (1 / pow(2, 0.1 * dist)); 
    }
    e.f = e.costeAcum + S * f.Q_total / QT; 
}

void astar(Estado& inicial, vector<Flow>& flows, vector<vector<UAV>>& uavs) {
    vector<Estado> pq; 
    inicial.f = 0; 
    for (int k1 = 0; k1 < inicial.uavs.size(); ++k1) {
        for (int k2 = 0; k2 < inicial.uavs[0].size(); ++k2) {
            inicial.uavs[k1][k2].band_width = get_bandwidth(inicial.uavs[k1][k2], inicial.t);
        }
    }
    pq.push_back(inicial);
    while (!pq.empty()) {
        Estado e = pq.back(); 
        pq.pop_back(); 
        if (e.t == T) {
            flows = e.flows; 
            uavs = e.uavs; 
            return; 
        }
        else {
            //Expandir el estado: 
            //sin avanzar tiempo 
            for (int flujo = 0; flujo < e.flows.size(); ++flujo) {
                for (int i = e.flows[flujo].m1; i <= e.flows[flujo].m2; ++i) {
                    for (int j = e.flows[flujo].n1; j <= e.flows[flujo].n2; ++j) {
                        //Generar Hijo: 
                        if (e.flows[flujo].remaining_Q == 0||e.uavs[i][j].band_width == 0 || e.flows[flujo].t_start >e.t) continue;
                        
                        Estado hijo = Estado{ e.flows, e.uavs, e.t, e.costeAcum, 0 }; 
                        
                        //actualizar flujo: 
                        if (hijo.flows[flujo].iLastDrone != -1 && hijo.flows[flujo].jLastDrone != -1 && (hijo.flows[flujo].iLastDrone != i || hijo.flows[flujo].jLastDrone != j)) {
                            ++hijo.flows[flujo].k; 
                            hijo.flows[flujo].score = hijo.flows[flujo].score + 0.1 * ((1 / double(e.flows[flujo].k)) - (1 / double(hijo.flows[flujo].k))); 
                        }
                        if (hijo.flows[flujo].iLastDrone == -1 && hijo.flows[flujo].jLastDrone == -1) { ++hijo.flows[flujo].k; }
                        hijo.flows[flujo].iLastDrone = i; 
                        hijo.flows[flujo].jLastDrone = j;
                        double q = min(e.flows[flujo].remaining_Q, e.uavs[i][j].band_width);
                        hijo.flows[flujo].remaining_Q -= q; 
                        double ratio = q / hijo.flows[flujo].Q_total;
                        hijo.flows[flujo].score += 0.4 * ratio + 0.2 * (10 / double((hijo.t + 10))) * ratio + 0.3 * ratio * (1 / pow(2, 0.1 * (hijo.flows[flujo].access_x <= hijo.flows[flujo].m2 && hijo.flows[flujo].access_x >= hijo.flows[flujo].m1 ? 0 : min(abs(hijo.flows[flujo].access_x - hijo.flows[flujo].m1), abs(hijo.flows[flujo].access_x - hijo.flows[flujo].m2))) + (hijo.flows[flujo].access_y <= hijo.flows[flujo].n2 && hijo.flows[flujo].access_x >= hijo.flows[flujo].n1 ? 0 : min(abs(hijo.flows[flujo].access_y - hijo.flows[flujo].n1), abs(hijo.flows[flujo].access_x - hijo.flows[flujo].n2)))));
                        
                        //actualizar el uav 
                        hijo.uavs[i][j].band_width -= q; 
                        
                        
                        //actualizar el coste del estado 
                        hijo.costeAcum += (hijo.flows[flujo].Q_total / QT) * (hijo.flows[flujo].score - e.flows[flujo].score); 
                        hijo.flows[flujo].schedule.push_back(make_tuple(hijo.t, i, j, q));
                        //calcular heur�stica
                        calcHeuristicF(hijo, hijo.flows[flujo]); 

                        if (pq.size() < MAX_SIZE) {
                            pq.push_back(hijo); 
                        }
                        else if (pq.front().f < hijo.f) {
                            pq[0] = hijo; 
                        }
                        sort(pq.begin(), pq.end()); 
                    }
                    
                }
            }
            //Avanzando en tiempo: 
            for (int flujo = 0; flujo < e.flows.size(); ++flujo) {
                for (int i = e.flows[flujo].m1; i <= e.flows[flujo].m2; ++i) {
                    for (int j = e.flows[flujo].n1; j <= e.flows[flujo].n2; ++j) {
                        //Generar Hijo: 
                        Estado hijo = Estado{ e.flows, e.uavs, e.t+1, e.costeAcum, 0 };
                        for (int k1 = 0; k1 < hijo.uavs.size(); ++k1) {
                            for (int k2 = 0; k2 < hijo.uavs[0].size(); ++k2) {
                                hijo.uavs[k1][k2].band_width = get_bandwidth(hijo.uavs[k1][k2], hijo.t);
                            }
                        }
                        if (e.flows[flujo].remaining_Q == 0 || hijo.uavs[i][j].band_width== 0 || e.flows[flujo].t_start > e.t + 1) continue;

                        //actualizar flujo: 
                        if (hijo.flows[flujo].iLastDrone != -1 && hijo.flows[flujo].jLastDrone != -1 && (hijo.flows[flujo].iLastDrone != i || hijo.flows[flujo].jLastDrone != j)) {
                            ++hijo.flows[flujo].k;
                            hijo.flows[flujo].score = hijo.flows[flujo].score + 0.1 * ((1 / double(e.flows[flujo].k)) - (1 / double(hijo.flows[flujo].k)));
                        }
                        if (hijo.flows[flujo].iLastDrone == -1 && hijo.flows[flujo].jLastDrone == -1) { ++hijo.flows[flujo].k; }
                        hijo.flows[flujo].iLastDrone = i;
                        hijo.flows[flujo].jLastDrone = j;
                        double q = min(e.flows[flujo].remaining_Q, e.uavs[i][j].band_width);
                        hijo.flows[flujo].remaining_Q -= q;
                        double ratio = q / hijo.flows[flujo].Q_total;
                        hijo.flows[flujo].score += 0.4 * ratio + 0.2 * (10 / double((hijo.t + 10))) * ratio + 0.3 * ratio * (1 / pow(2, 0.1 * (hijo.flows[flujo].access_x <= hijo.flows[flujo].m2 && hijo.flows[flujo].access_x >= hijo.flows[flujo].m1 ? 0 : min(abs(hijo.flows[flujo].access_x - hijo.flows[flujo].m1), abs(hijo.flows[flujo].access_x - hijo.flows[flujo].m2))) + (hijo.flows[flujo].access_y <= hijo.flows[flujo].n2 && hijo.flows[flujo].access_x >= hijo.flows[flujo].n1 ? 0 : min(abs(hijo.flows[flujo].access_y - hijo.flows[flujo].n1), abs(hijo.flows[flujo].access_x - hijo.flows[flujo].n2)))));
                        

                        //actualizar el uav 
                        hijo.uavs[i][j].band_width -= q;
                        
                        //actualizar el coste del estado 
                        hijo.costeAcum += (hijo.flows[flujo].Q_total / QT) * (hijo.flows[flujo].score - e.flows[flujo].score);
                        hijo.flows[flujo].schedule.push_back(make_tuple(hijo.t, i, j, q)); 
                        //calcular heur�stica
                        calcHeuristicF(hijo, hijo.flows[flujo]);
                        //boostear
                        hijo.f = hijo.f * BOOST_FACTOR + BOOST_ADD; 
                        if (pq.size() < MAX_SIZE) {
                            pq.push_back(hijo);
                        }
                        else if (pq.front().f < hijo.f) {
                            pq[0] = hijo;
                        }
                        sort(pq.begin(), pq.end());
                    }
                }
            }
            //avanzar sin hacer nada 
            e.t++; 
            //regenerar los uavs 
            for (int k1 = 0; k1 < e.uavs.size(); ++k1) {
                for (int k2 = 0; k2 < e.uavs[0].size(); ++k2) {
                    e.uavs[k1][k2].band_width = get_bandwidth(e.uavs[k1][k2], e.t);
                }
            }
            //boostear
            e.f = e.f * BOOST_FACTOR + BOOST_ADD;
            if (pq.size() < MAX_SIZE) {
                pq.push_back(e);
            }
            else if (pq.front().f < e.f) {
                pq[0] = e;
            }
            sort(pq.begin(), pq.end());
        }
    }


}


int manhattan_distance(int x1, int y1, int x2, int y2) {return abs(x1 - x2) + abs(y1 - y2);}

void solve(vector<vector<UAV>>& uavs, vector<Flow>& flows) {
    Estado inicial = Estado{flows, uavs, 0, 0,0};
    inicial.flows = flows; 
    inicial.uavs = uavs; 
    astar(inicial, flows, uavs); 
}

/*
void solve() {
    for (int t = 0; t < T; ++t) {
        vector<vector<double>> available_bw(M, vector<double>(N, 0.0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                available_bw[i][j] = get_bandwidth(uavs[i][j], t);
            }
        }
        vector<TransmissionRequest> requests;
        for (int i = 0; i < FN; ++i) {
            if (flows[i].t_start <= t && flows[i].remaining_Q > 1e-9) {
                for (int lx = flows[i].m1; lx <= flows[i].m2; ++lx) {
                    for (int ly = flows[i].n1; ly <= flows[i].n2; ++ly) {
                        if (available_bw[lx][ly] > 1e-9) {
                            int dist = manhattan_distance(flows[i].access_x, flows[i].access_y, lx, ly);
                            requests.push_back({i, lx, ly, dist});
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
                flows[flow_idx].schedule.push_back(make_tuple(t, uav_x, uav_y, amount_to_send));
            }
        }
    }
}
*/
int main() {
    vector<vector<UAV>> uavs;
    vector<Flow> flows;
    

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
    QT = 0; 
    for (int i = 0; i < FN; ++i) {
        int id, ax, ay, ts, m1, n1, m2, n2;
        double qt;
        cin >> id >> ax >> ay >> ts >> qt >> m1 >> n1 >> m2 >> n2;
        flows[i] = {id, ax, ay, ts, qt, m1, n1, m2, n2, qt,0};
        QT += qt; 
    }

    solve(uavs, flows);

    cout << fixed << setprecision(5);
    for (const auto& flow : flows) {
        cout << flow.id << " " << flow.schedule.size() << "\n";
        for (const auto& record : flow.schedule) {
            cout << get<0>(record) << " " << get<1>(record) << " " << get<2>(record) << " " << get<3>(record) << "\n";
        }
    }
}
