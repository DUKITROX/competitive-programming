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
    string S, s1,s2;
    int n;
    cin >> S >> n >> s1 >> s2;

    int j = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(s2[i] - s1[i] < 0){
            count = n;
            break;
        }
        set<int> G;
        int size = s2[i] - s2[j] + 1;
        while(j < S.length() && G.size() < size){
            if(s1[i] <= S[j] && S[j] <= s2[i] && !G.count(S[j])){
                G.insert(S[j]);
            }
            j++;
        }
        if(G.size() == size) count++;
    }
    if(count == n) cout << "NO\n";
    else cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}