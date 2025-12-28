#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

// Helper to get a random integer in [min, max]
int random_int(mt19937& rng, int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// Helper to get a random double in [min, max)
double random_double(mt19937& rng, double min, double max) {
    uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

int main() {
    // Initialize a good random number generator
    std::mt19937 rng(std::random_device{}());

    // --- 1. Generate M, N, FN, T ---
    // Constraints: 1 < M, N < 70, 1 <= FN < 5000, 1 < T < 500
    int M = random_int(rng, 5, 30);  // Stay within reasonable bounds
    int N = random_int(rng, 5, 30);
    int FN = random_int(rng, 10, 200);
    int T = random_int(rng, 50, 499);

    cout << M << " " << N << " " << FN << " " << T << "\n";

    // --- 2. Generate UAV Grid (M*N lines) ---
    cout << fixed << setprecision(2);
    for (int x = 0; x < M; ++x) {
        for (int y = 0; y < N; ++y) {
            // Constraints: 0 < B < 1000, 0 <= phi < 10
            double B = random_double(rng, 10.0, 500.0);
            int phi = random_int(rng, 0, 9);
            cout << x << " " << y << " " << B << " " << phi << "\n";
        }
    }
    cout << fixed << setprecision(0); // Back to integers

    // --- 3. Generate Flows (FN lines) ---
    for (int i = 1; i <= FN; ++i) {
        int f = i;
        int access_x = random_int(rng, 0, M - 1);
        int access_y = random_int(rng, 0, N - 1);
        int t_start = random_int(rng, 0, T - 1); // Can start at any time
        
        // Constraint: 1 <= Q_total < 3000
        int Q_total = random_int(rng, 1, 2999);
        
        // Generate a valid landing range [m1, n1], [m2, n2]
        // Ensure m1 <= m2 and n1 <= n2
        int m1 = random_int(rng, 0, M - 1);
        int m2 = random_int(rng, m1, M - 1); // m2 must be >= m1
        int n1 = random_int(rng, 0, N - 1);
        int n2 = random_int(rng, n1, N - 1); // n2 must be >= n1

        cout << f << " " << access_x << " " << access_y << " " 
             << t_start << " " << Q_total << " " 
             << m1 << " " << n1 << " " << m2 << " " << n2 << "\n";
    }

    return 0;
}