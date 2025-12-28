#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){cout << arr[0]; for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

bool pert(ii inter, int val){
    if(inter.first <= val && val <= inter.second) return true;
    else return false;
}

void solve(){
    ll n,k; cin >> n >> k; vi arr(n);
    int ant,act; cin >> ant;
    if(ant != 1) {
        cout << "1\n";
        for(int i = 1; i < n; i++) cin >> act;
    }else if(n==1) cout << k+1 << "\n";
    else{
        queue<pair<ii,int> > q;
        for(int i = 1; i < n; i++){
            cin >> act;
            if(act-ant>1){
                q.push(make_pair(make_pair(ant+1-i,act-1-i), i));
            }
            ant = act;
        }
        ll sol = 1;
        for(int i = 0; i < k; i++){
            while(!q.empty() && !pert(q.front().first,sol)) q.pop();
            if(q.empty()) sol += n;
            else sol += q.front().second;
        }
        cout << sol << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}