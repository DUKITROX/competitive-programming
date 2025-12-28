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
template<typename T> ostream &operator<<(ostream &os, set<T>& s){auto it = s.begin(); os << *it; ++it; while(it != s.end()){os << " " << *it;++it;} return os;} 

void solve(){
    int n; cin >> n;
    vi arr; arr.push_back(n%10);
    int aux = n/10; while(aux){arr.push_back(aux%10); aux/= 10;}
    reverse(arr.begin(), arr.end());
    int top = 1<<(arr.size()-1), mask = 0;
    set<int> sol;
    while(mask < top){
        int fin = 0,temp = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(mask&(1<<(i-1))){
                fin += temp;
                temp = arr[i];
            }else{
                temp *= 10;
                temp += arr[i];
            }
        }
        fin += temp;
        sol.insert(fin);
        mask++;
    }
    cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}