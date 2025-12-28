#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

void solve(){
    int n, k; cin >> n >> k; k <<= 1;
    vi a1(n), a2(n); cin >> a1 >> a2; sort(a1); sort(a2);
    vector<int> s11,s12,s22,s21;
    for(int i = 1; i < n; i++){
        if(a1[i-1] == a1[i]){
            s11.push_back(a1[i]);
            i++;
        }else{
            s12.push_back(a1[i-1]);
        }
    }
    if(a1[n-1] != a1[n-2]) s12.push_back(a1[n-1]);
    for(int i = 1; i < n; i++){
        if(a2[i-1] == a2[i]){
            s22.push_back(a2[i]);
            i++;
        }else{
            s21.push_back(a2[i-1]);
        }
    }
    if(a2[n-1] != a2[n-2]) s21.push_back(a2[n-1]);
    int j = 0, i = 0;
    while(j < k - 1 && i < s11.size()){
        cout << s11[i] << " " << s11[i] << " "; j+=2; i++;
    } 
    i = 0;
    while(j < k){
        cout << s12[i] << " "; j++; i++;
    }
    j = 0; i = 0;
    cout << "\n";
    while(j < k - 1 && i < s22.size()){
        cout << s22[i] << " " << s22[i] << " "; j+=2; i++;
    } 
    i = 0;
    while(j < k){
        cout << s21[i] << " "; j++; i++;
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}