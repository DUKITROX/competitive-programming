#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
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
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;};
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;};
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

struct Trie {
    int prefixes, words;
    vector<Trie*> child;
    Trie() : prefixes(0), words(0), child(26, nullptr) {}
    ~Trie() { for(int i = 0; i < 26; i++) delete child[i]; }
    void add(string const& s, int i = 0) {
        ++prefixes;
        if (i >= s.size()) ++words;
        else (child[s[i]-'a'] == nullptr ? child[s[i]-'a'] = new Trie() : child[s[i]-'a'])->add(s, i + 1);
    }
};

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}