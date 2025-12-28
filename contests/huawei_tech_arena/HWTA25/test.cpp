#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Stores the original "ground truth" for a flow,
 * needed for scoring.
 */
struct FlowTruth {
    int id;
    int access_x, access_y;
    double Q_total;
};

/**
 * @brief Calculates Manhattan distance between two points.
 */
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- 1. Read Original Problem Input ---
    // We must read the original input to get Q_total and access points
    // for each flow, which are required for scoring.

    int M, N, FN, T;
    cin >> M >> N >> FN >> T;

    // Skip the M*N UAV definition lines
    string line;
    getline(cin, line); // Consume the rest of the first line
    for (int i = 0; i < M * N; ++i) {
        getline(cin, line);
    }

    map<int, FlowTruth> flow_truths;
    double total_q_all_flows = 0.0;

    // Read the FN flow definition lines
    for (int i = 0; i < FN; ++i) {
        int f, x, y, t_start, m1, n1, m2, n2;
        double Q_total;
        cin >> f >> x >> y >> t_start >> Q_total >> m1 >> n1 >> m2 >> n2;
        flow_truths[f] = {f, x, y, Q_total};
        total_q_all_flows += Q_total;
    }

    // --- 2. Read Solution Output & Calculate Score ---

    double final_total_score = 0.0;
    
    // We expect FN blocks of output, one for each flow
    for (int i = 0; i < FN; ++i) {
        int flow_id, p;
        if (!(cin >> flow_id >> p)) {
            // Handle cases where the solution might not output all flows
            // (though a valid one should)
            break;
        }

        const FlowTruth& truth = flow_truths[flow_id];
        if (truth.Q_total < 1e-9) { // Avoid division by zero for empty flows
             for (int j = 0; j < p; ++j) getline(cin, line); // Skip p lines
             continue;
        }

        double total_sent_for_flow = 0.0;
        double delay_score_comp = 0.0;
        double dist_score_comp = 0.0;
        
        int k = 1; // Landing point counter
        int last_x = -1, last_y = -1;
        bool first_transmission = true;

        for (int j = 0; j < p; ++j) {
            int t, x, y;
            double z;
            cin >> t >> x >> y >> z;

            if (z < 1e-9) continue; // Ignore zero-traffic records

            // --- Component 1: Total U2G Traffic ---
            total_sent_for_flow += z;

            // --- Component 2: Traffic Delay Score ---
            // Tmax is 10 by default
            delay_score_comp += (10.0 / (t + 10.0)) * (z / truth.Q_total);

            // --- Component 3: Transmission Distance Score ---
            // alpha is 0.1 by default
            int d = manhattan_distance(truth.access_x, truth.access_y, x, y);
            dist_score_comp += (z / truth.Q_total) * pow(2.0, -0.1 * d);

            // --- Component 4: Landing UAV Point Score ---
            if (first_transmission) {
                last_x = x;
                last_y = y;
                first_transmission = false;
            } else if (x != last_x || y != last_y) {
                k++;
                last_x = x;
                last_y = y;
            }
        }

        // --- Calculate Final Score for this Flow ---

        // Score 1: Total U2G Traffic Score
        double s1_traffic = total_sent_for_flow / truth.Q_total;

        // Score 2: Traffic Delay Score
        double s2_delay = delay_score_comp;

        // Score 3: Transmission Distance Score
        double s3_distance = dist_score_comp;

        // Score 4: Landing UAV Point Score
        double s4_landing = 1.0 / k;

        // Per-flow score
        double flow_score = 100.0 * (
            0.4 * s1_traffic +
            0.2 * s2_delay +
            0.3 * s3_distance +
            0.1 * s4_landing
        );
        
        // Add to final total score, weighted by this flow's Q_total
        if (total_q_all_flows > 1e-9) {
            final_total_score += (truth.Q_total / total_q_all_flows) * flow_score;
        }
    }

    // --- 3. Output Final Score ---
    cout << fixed << setprecision(5) << final_total_score << endl;

    return 0;
}
