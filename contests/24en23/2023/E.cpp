#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;

const int INF = 1e9+7;

void show(vi arr){for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";cout << "\n";}
void show(vii arr){for(int i = 0; i < arr.size(); i++) cout << arr[i].first << " " << arr[i].second << "\n";}

int n,p,a,N;

int d(int dp[1001][1001], vii& choice, int i, int cant){
    if(i >= N) return 0;
    if(dp[i][cant]) return dp[i][cant];

    int ans1=0,ans2=0,ans3=0;
    if(choice[i].first + cant <= a) ans1 = choice[i].first + d(dp, choice, i+1, cant+choice[i].first);
    if(choice[i].second + cant <= a) ans2 = choice[i].second + d(dp, choice, i+1, cant+choice[i].second);
    ans3 = d(dp, choice, i+1, cant);

    ans1 = max(ans1, ans3);
    return dp[i][cant] = max(ans1, ans2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> p >> a){
        vvi arr(n);
        vector<bool> visited(n, false);
        vii choice;
        for(int i = 0; i < p; i++){
            int a,b; cin >> a>> b; a--;b--;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vi col(n);
                col[i] = 0;
                queue<int> q;
                int blue=0, red=0;
                q.push(i);
                while(!q.empty()){
                    int u = q.front(); q.pop();
                    visited[u] = true;
                    if(col[u]) blue++;
                    else red++;
                    for(auto v : arr[u]){
                        if(!visited[v]){
                            if(col[u] == 0) col[v] = 1;
                            else col[v] = 0;
                            q.push(v);
                        }
                    }
                }
                choice.push_back(make_pair(red,blue));
            }
        }
        N = choice.size();
        //vvi dp(n,vi(n,0));
        int dp[1001][1001];
        cout << d(dp, choice, 0, 0) << "\n";
    }
}