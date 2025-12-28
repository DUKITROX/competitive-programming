#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
#define first ff
#define second ss
const int INF = 1e9+7;

void solve(){
    queue<int> q;
    set<int> s;
    int n; cin >> n;
    vvi arr(n);
    vi numChild(n,0);
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(arr[i].size() == 1) {
            if(!s.count(arr[i][0])){
                q.push(arr[i][0]);
                s.insert(arr[i][0]);
            }
            numChild[arr[i][0]]++;
        }
    }
    bool pos = true;
    while(!q.empty() && pos){
        int a = q.front(); q.pop();
        if(numChild[a] > 3){
            pos = false;
        }else if(numChild[a] == 2){
            
        }else{

        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
