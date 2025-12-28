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

struct UFDS{
    vector<ll> p,setSize;
    int numSets;
    ll maxSet;
    UFDS(int n){
        p.assign(n,0);
        setSize.assign(n,1);
        numSets = n;
        maxSet = 1;
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    void merge(int x, int y){
        int i = find(x); int j = find(y);
        if(i==j) return;
        p[i] = j;
        setSize[j] += setSize[i];
        maxSet = max(maxSet, setSize[j]);
        numSets--;
    }
    int size(int i) {return setSize[find(i)];}
};

void solve(){
    int n,k; cin >> n >> k; vi arr(n),join(k+1,0),disjoin(k+1,0); cin >> arr;
    int act = arr[0],cont=1;
    for(int i = 1; i < n; i++){
        if(arr[i] == act)cont++;
        else{
            join[arr[i-1]] = max(join[arr[i-1]], cont);
            cont = 1;
        }
        act = arr[i];
    }
    join[arr[n-1]] = max(join[arr[n-1]],cont);

    vii arrn(n);for(int i = 0; i < n; i++)arrn[i] = make_pair(arr[i],i);sort(arrn.begin(),arrn.end(),greater<ii>());
    set<int> s;
    UFDS ufds(n);
    for(int i = 0; i < n; i++){
        if(s.count(arrn[i].second-1)) ufds.merge(arrn[i].second-1, arrn[i].second);
        if(s.count(arrn[i].second+1)) ufds.merge(arrn[i].second+1, arrn[i].second);
        s.insert(arrn[i].second);
        disjoin[arrn[i].first] = ufds.maxSet;
    }
   // show(join);show(disjoin);
    for(int i = 1; i <= k; i++){
        cout << join[i]+disjoin[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}