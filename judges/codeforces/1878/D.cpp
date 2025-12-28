#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void reverse(string& s, int a, int b){
    int i = a, j = b, t;
    while(i < j){
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;j--;
    }
}

void solve(){
    int n,k,q,x; cin >> n >> k; string s; cin >> s; vi l(k+1),r(k+1),f(n+1);
    for(int i = 1; i <= k; i++) {cin >> l[i];}
    for(int i = 1; i <= k; i++) {cin >> r[i];}
    cin >> q;
    
    while(q--){
        cin >> x;
        int i = (upper_bound(l.begin(), l.end(), x) - l.begin() - 1);
        int a = min(x, r[i]+l[i]-x); f[a]++;
    }
    for(int i = 1; i <= k; i++){
        int sum = 0;
        for(int j = l[i]; j <= l[i] + (r[i] - l[i])/2; j++){
            sum += f[j];
            if(sum%2) swap(s[j-1],s[r[i]-j+l[i]-1]);
        }
    }
    cout << s << "\n";
}
/*
5
4 2
abcd
1 3
2 4
2
1 3
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}