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

ll diez (ll a){
    ll sol = 1;
    while(a--) sol*=10;
    return sol;
}
int len(ll a){
    int cont = 0;
    while(a){
        cont++;
        a /= 10;
    }
    return cont;
}

void solve(){
    ll A,B,C,k; cin >> A >> B >> C >> k;
    ll cont = 0;
    ll Cm = diez(C-1), CM = diez(C)-1;
    ll Am = diez(A-1), AM = diez(A)-1;
    ll Bm = diez(B-1), BM = diez(B)-1;
    ll ABm = Am+Bm, ABM = AM+BM;
    ll Ap = AM-Am+1;
    ll Bp = BM-Bm+1;
    ll CP = CM-Cm+1;

    bool pos = true;
    for(int i = Am; i <= AM && pos; i++){
        for(int j = Bm; j <= BM && pos; j++){
            if(len(i+j) == C) cont++;
            if(cont == k) cout << i << " + " << j << " = " << i+j << "\n";
        }
    }
    if(!pos || cont < k) cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}