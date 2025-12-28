#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAXN = 200000;

vector<int> adj[MAXN];
int distA[MAXN];
int distB[MAXN];
int color[MAXN];

void bfs(int start, int n, int dist[]) {
    fill(dist, dist + n, MAXN);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
            if (dist[u] == MAXN) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        a--; b--; // Adjusting to 0-based index
        
        // Reset for each test case
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            color[i] = 0; // 0 = white, 1 = red, 2 = blue
        }
        
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--; // Adjusting to 0-based index
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        bfs(a, n, distA);
        bfs(b, n, distB);
        
        if (a == b) {
            color[a] = 2; // Initial position is the same, so it's blue
        } else {
            color[a] = 1; // Initial position of P_A is red
        }
        
        queue<int> qa, qb;
        if (a != b) {
            qa.push(a);
            qb.push(b);
        } else {
            qb.push(a);
        }
        
        int steps = 0;
        while (!qa.empty() || !qb.empty()) {
            int qaSize = qa.size();
            int qbSize = qb.size();
            
            // Move P_A
            for (int i = 0; i < qaSize; ++i) {
                int v = qa.front();
                qa.pop();
                
                for (int u : adj[v]) {
                    if (color[u] == 0) {
                        color[u] = 1;
                        qa.push(u);
                    }
                }
            }
            
            // Move P_B
            for (int i = 0; i < qbSize; ++i) {
                int v = qb.front();
                qb.pop();
                
                for (int u : adj[v]) {
                    if (color[u] == 1) {
                        color[u] = 2;
                        qb.push(u);
                    }
                }
            }
            
            steps++;
        }
        
        cout << steps << "\n";
    }
    
    return 0;
}
