#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 998244353;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

//Efficient way to calculate powers
ll binExp(ll a, ll b){
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res%INF * a%INF)%INF;
        a = (a%INF * a%INF)%INF;
        b >>= 1;
    }
    return res%INF;
}

struct UFDS{
    vector<ll> p,setSize;
    int numSets;
    UFDS(int n){
        p.assign(n,0);
        setSize.assign(n,1);
        numSets = n;
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    void merge(int x, int y){
        int i = find(x); int j = find(y);
        if(i==j) return;
        p[i] = j;
        setSize[j] += setSize[i];
        numSets--;
    }
    int size(int i) {return setSize[find(i)];}
};

void solve(){
    int num,S; cin >> num >> S;
    vector<pair<int,ii> > tree(num-1);
    vector<ll> memo(num+1,1);
    for(int i = 0; i < num-1; i++) cin >> tree[i].second.first >> tree[i].second.second >> tree[i].first;
    sort(tree.begin(), tree.end());
    UFDS ufds(num+1);
    for(int i = 0; i < num-1; i++){
        int n = tree[i].second.first, m = tree[i].second.second, min = tree[i].first;
        n = ufds.find(n), m = ufds.find(m);
        ll a = S-min+1;
        ll b = (ufds.size(n)%INF*ufds.size(m)%INF)%INF-1;
        ll pos = binExp(a,b)%INF;
        //cout << i << " : " << a << " " << b << " " << pos;
        ll N = memo[n], M = memo[m];
        ufds.merge(n,m);
        n = ufds.find(m);
        memo[n] = ((N%INF*M%INF)%INF*pos%INF)%INF;
        //cout << " : " << memo[n] << endl;
    }
    cout << memo[ufds.find(1)]%INF << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}

/*
1
4 5
1 2 2
2 3 4
3 4 3


4
2 5
1 2 4
4 5
1 2 2
2 3 4
3 4 3
5 6
1 2 3
1 3 2
3 4 6
3 5 1
10 200
1 2 3
2 3 33
3 4 200
1 5 132
5 6 1
5 7 29
7 8 187
7 9 20
7 10 4

*/