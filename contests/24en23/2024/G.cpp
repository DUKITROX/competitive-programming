#include <bits/stdc++.h>
#include <random>
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
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i]; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

bool solve(ifstream& file){
    ll n; file >> n; if(n==0) return false;
    bool f = true;
    while(n != 0){
        vector<char> sol;
        while(n){
            sol.push_back((char)((n-1)%26 + 'A'));
            n=(n-1)/26;
        }
        reverse(sol.begin(), sol.end());
        if(f) f = false;
        else cout << " ";
        cout << sol;
        file >> n;
    }
    cout << "\n";
    return true;
}

int traducir(ll n, string& sol){
    if(n<=26){
        sol[0]='A'+n-1;
        return 0;
    }
    int i = traducir((n-1)/26,sol);
    if(n%26 == 0){
        sol[i]--;
        sol[++i] = 'Z';
    }else
        sol[++i] = 'A' + ((n-1)%26);
        return i;
}
bool solve2(ifstream& file){
    ll n; file >> n; if(!n) return false;
    vector<ll> v;
    while(n){
        v.push_back(n);
        file >> n;
    }
    string sol;
    sol.resize(12);
    int size = traducir(v[0], sol) + 1;
    sol.resize(size);
    cout << sol;
    for(int i = 1; i < v.size(); i++){
        sol.resize(12);
        size = traducir(v[i], sol) + 1;
        sol.resize(size);
        cout << ' ' << sol;
    }
    cout << "\n";
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    mt19937 rng(123);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 23; j++){
            cout << rng()%1000LL << " ";
        }
        cout << "0\n";
    }
    */
    ifstream file("casos.txt");
    while(solve2(file));
    file.close();
}