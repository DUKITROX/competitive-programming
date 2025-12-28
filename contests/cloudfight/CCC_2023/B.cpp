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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n;
bool inBounds(ii u){
    return (u.first >= 0 && u.first < n && u.second >= 0 && u.second < n);
}

ofstream file;

void solve(){
    cin >> n; vector<string> arr(n); cin >> arr;
    int q; cin >> q;
    while(q--) {
        int a,b,c,d;char k;
        cin >> a >> k >> b >> c >> k >> d;
        ii sol = make_pair(d,c);
        ii ini = make_pair(b,a);

        if(sol == ini){
            file << "SAME\n";
            continue;
        }

        bool p = false;
        queue<ii> qu;
        map<ii,bool> visited;
        qu.push(make_pair(b,a));
        while(!qu.empty()){
            ii u = qu.front(); qu.pop();
            if(u == sol) {
                p = true;
                break;
            }
            visited[u] = true;
            for(int i = 0; i < 4; i++){
                ii v;
                v.first = u.first + dx[i];
                v.second = u.second + dy[i];
                if(visited.find(v) == visited.end() && inBounds(v) && arr[v.first][v.second] == 'L'){
                    visited[v] = true;
                    qu.push(v);
                }
            }
        }
        if(p) file << "SAME\n";
        else file << "DIFFERENT\n";
    }
}
int main(){
    file.open("B5.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    file.close();
}
/*

11 WWWWWWWWWWW WLWWWWWWWWW WWWWLLLLWWW WWWLLLLLWWW WWWLWWWLLWW WWLLWLWWLWW WWLLWWWWWWW WWWWLWWWLWW WWLWWWLLWWW WLLWWWWWWWW WWWWWWWWWWW
3
4,2 8,5
3,5 4,7
5,5 7,8
*/