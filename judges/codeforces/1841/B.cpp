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
    int n,ant, act, m=0,M,MM; cin >> n;
    bool f = false;
    cin >> ant;
    M = ant;
    MM = ant;
    cout << "1";
    for(int i = 1; i < n; i++){
        cin >> act;
        if(!f){
            if(act >= MM){
                cout << "1";
                MM = act;
            }else{
                if(act <= M){
                    f = true;
                    cout << "1";
                    m = act;
                }else{
                    cout << "0";
                }
            }
        }else{
            if(act >= m && act <= M) {
                cout << "1";
                m = act;
            }else cout << "0";
        }
        ant = act;
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}