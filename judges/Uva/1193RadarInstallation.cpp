#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
typedef long long ll;
typedef long double db;
typedef pair<int,int> ii;
typedef pair<db, db> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const db EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

dd comp(pair<db,db> p, long double d){
    double x1 = p.f - sqrt(d*d - p.s*p.s);
    double x2 = p.f + sqrt(d*d - p.s*p.s);
    return make_pair(x1,x2);
}

bool cmp (dd p1, dd p2){
    if(p1.s < p2.s)return true;
    else if(p1.s == p2.s && p1.f < p2.f) return true;
    return false;
}

bool solve(int t){
    db d; int n, cont = 0; cin >> n >> d; vector<dd> arr(n), inter(n);
    if(!n && !d) return false;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].f >> arr[i].s;
        if(arr[i].s > d) cont = -1;
    }
    if(cont == -1){
        cout << "Case " << t << ": ";
        cout << cont << "\n";
        return true;
    }

    for(int i = 0; i < n; i++) inter[i] = comp(arr[i], d);
    sort(inter.begin(), inter.end(), cmp);
    //for(int i = 0; i < n; i++) cout << "(" << inter[i].f << ", " << inter[i].s << ")\n";
    
    int l = 0, r = 0;
    while(r < n){
        while(r < n && inter[r].f <= inter[l].s) r++;
        l = r;
        cont++;
    }
    cout << "Case " << t << ": " << cont << "\n";
    return true;
}
/*
(2)
13 90
22 60
16 57
32 32
-48 37
-45 38
45 75
-4 9
-5 13
-23 25
-4 19
-45 82
9 58
18 41

(4)
12 21
27 1
16 19
12 6
-12 17
-2 16
-49 4
-13 12
46 12
48 4
-46 6
26 14
-22 10
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(solve(t)) t++;
}