#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

void solve(){
    string s1,s2;
    int t,q,a;
    cin >> s1 >> s2 >> t >> q;
    for(int i = 0; i < q; i++){
        cin >> a;
        if(a == 1){

        }else if(a == 2){
            int a1,a2,p1,p2;
            char c;
            cin >> a1 >> p1 >> a2 >> p2; p1--; p2--;
            if(a1 == 1){
                c = s1[p1];
                if(a2 == 1) {
                    s1[p1] = s1[p2];
                    s1[p2] = c;
                }else{
                    s1[p1] = s2[p2];
                    s2[p2] = c;
                }
            }else{
                c = s2[p1];
                if(a2 == 1){
                    s2[p1] = s1[p2];
                    s1[p2] = c;
                }else{
                    s2[p1] = s2[p2];
                    s2[p2] = c;
                }
            }
        }else{
            if(s1 == s2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}