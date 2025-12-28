#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    int n; cin >> n; vii arr(n); vi b(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first; arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int cont = 0, c = 1;
    for(int i = 1; i < n; i++){
        if(arr[i].first == arr[i-1].first){
            if(c==1)cont++;
            if(cont == 1) b[arr[i].second] = 2;
            else b[arr[i].second] = 3;
            c++;
        }else{
            c = 1;
        }
    }
    if(cont <= 1) cout << "-1\n";
    else {
        for(int i = 0; i < n; i++){
            if(b[i]) cout << b[i] << " ";
            else cout << "1 ";
        }
        cout << "\n";
    }
}
/*
6
1 2 3 2 2 3
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}