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

int dy8[8] = {0,1,0,-1,-1,1,1,-1};
int dx8[8] = {1,0,-1,0,1,1,-1,-1};

int n;
bool inBounds(ii u){
    return (u.first >= 0 && u.first < n && u.second >= 0 && u.second < n);
}

ofstream file;

void minPath(ii ini, vector<string>& arr, set<ii> perimetro){
    queue<ii> qu;
    map<ii,bool> visited;
    vii sol;

    qu.push(ini);
    while(!qu.empty()){
        ii u = qu.front(); qu.pop();
        visited[u] = true;
        sol.push_back(u);

        for(int i = 0; i < 8; i++){
        ii v; v.first = u.first + dx8[i]; v.second = u.second + dy8[i];
            if(visited.find(v) == visited.end() && inBounds(v) && arr[v.first][v.second] == 'W' && perimetro.count(v)){
                visited[v] = true;
                qu.push(v);
                break;
            }
        }
    }
    for(int i = 0; i < sol.size(); i++){
        file << sol[i].first << "," << sol[i].second << " ";
    }
    file << "\n";
}

ii nextToWater(ii u, vector<string>& arr, set<ii>& perimetro){
    for(int i = 0; i < 8; i++){
        ii v = make_pair(u.first+dx8[i], u.second+dy8[i]);
        if(inBounds(v) && arr[v.first][v.second] == 'W'){
            perimetro.insert(v);
        }
    }
    return make_pair(-1,-1);
}

void solve(){
    cin >> n; vector<string> arr(n); cin >> arr;
    int q; cin >> q;
    while(q--) {
        int a,b;char k;
        cin >> a >> k >> b;
        ii ini = make_pair(b,a), SOL;

        bool p = false;
        set<ii> perimetro;
        queue<ii> qu;
        map<ii,bool> visited;

        qu.push(ini);
        while(!qu.empty()){
            ii u = qu.front(); qu.pop();
            visited[u] = true;
            nextToWater(u,arr,perimetro);
            for(int i = 0; i < 4; i++){
                ii v; v.first = u.first + dx[i]; v.second = u.second + dy[i];
                if(visited.find(v) == visited.end() && inBounds(v) && arr[v.first][v.second] == 'L'){
                    visited[v] = true;
                    qu.push(v);
                }
            }
        }
        ii INI = *perimetro.begin();
        
        minPath(INI, arr, perimetro);
    }
}
int main(){
    file.open("E1.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    file.close();
}
/*
11 WWWWWWWWWWW WLWWWWWWWWW WWWWLLLLWWW WWWLLLLLWWW WWWLWWWLLWW
WWLLWLWWLWW WWLLWWWWWWW WWWWLWWWLWW WWLWWWLLWWW WLLWWWWWWWW WWWWWWWWWWW
3
5,5
7,3
7,8
*/