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

ofstream file;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n;
bool inBounds(ii u){
    return (u.first >= 0 && u.first < n && u.second >= 0 && u.second < n);
}

void solve(){
    cin >> n; vector<string> arr(n); cin >> arr;
    int q; cin >> q;
    cin.ignore();
    while(q--){
        string s; getline(cin,s); stringstream ss(s);
        bool p = true;
        int a,b; char c;
        set<ii> S;
        ii prev = make_pair(-1,-1);
        while(ss >> a >> c >> b){        
            //cout << a << c << b << endl;
            if(S.count(make_pair(a,b))) p = false;
            if(prev == make_pair(-1,-1)){
            }else if(a+1 == prev.first && b+1 == prev.second){
                if((S.count(make_pair(a+1,b)) && S.count(make_pair(a,b+1))) ) p = false;
            }else if(a-1 == prev.first && b+1 == prev.second){
                if((S.count(make_pair(a-1,b)) && S.count(make_pair(a,b+1))) ) p = false;
            }else if(a-1 == prev.first && b-1 == prev.second){
                if((S.count(make_pair(a-1, b)) && S.count(make_pair(a, b-1)))) p = false;
            }else if(a+1 == prev.first && b-1 == prev.second){
                if((S.count(make_pair(a+1,b)) && S.count(make_pair(a,b-1)))) p = false;
            }
            S.insert(make_pair(a,b));
            prev.first = a; prev.second = b;
        }

        if(p) file << "VALID\n";
        else file << "INVALID\n";
    }
}
int main(){
    file.open("C5.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    file.close();
}
/*
11
WWWWWWWWWWW
WLWWWWWWWWW
WWWWLLLLWWW
WWWLLLLLWWW
WWWLWWWLLWW
WWLLWLWWLWW
WWLLWWWWWWW
WWWWLWWWLWW
WWLWWWLLWWW
WLLWWWWWWWW
WWWWWWWWWWW
4
2,3 2,4 1,5 1,6 2,7 3,7 4,6 5,6
9,4 9,5 8,6 7,7 8,8 9,7 8,6 7,5
6,1 7,1 8,2 9,3 8,3 9,2 10,1
0,3 0,2 0,1 1,0 2,1 1,2 1,3
*/