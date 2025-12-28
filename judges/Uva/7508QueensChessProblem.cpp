#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

int row[8], a, b, cont = 1;

bool canPlace(int r, int c){
    for(int prev = 0; prev < c; prev++){
        if(row[prev] == r || abs(row[prev] - r) == abs(prev - c)) return false;
    }
    return true;
}

void backtrack(int c){
    if(c == 8 && row[b] == a){
        if(cont < 10) cout << " ";
        cout << cont << "     ";
        for(int i = 0; i < 8; i++) cout << " " << row[i]+1;
        cout << "\n";
        cont++;
        return;
    }
    for(int r = 0; r < 8; r++){
        if(c == b && r != a) continue;
        if(canPlace(r,c)){
            row[c] = r;
            backtrack(c+1);
        }
    }
}

void solve(int t){
    cin >> a >> b; a--; b--;
    cont = 1;
    row[b] = a;
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n\n";
    backtrack(0);
    if(t) cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve(t);
}