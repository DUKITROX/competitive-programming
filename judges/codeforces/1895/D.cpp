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
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    int n; cin >> n; vector<string> arr(n); cin >> arr;
    map<int,int> uno,dos,tres,cuatro,cinco; ll sol = 0;
    for(int i = 0; i < n; i++){
        int l = arr[i].length();
        int sum = 0; for(auto a : arr[i]) sum += a - '0';
        switch (l){
            case 1:
                uno[sum]++;
                break;
            case 2:
                dos[sum]++;
                break;
            case 3:
                tres[sum]++;
                break;
            case 4:
                cuatro[sum]++;
                break;
            case 5:
                cinco[sum]++;
                break;
        }
    }
    for(int i = 0; i < n; i++){
        int l = arr[i].length();
        int sum = 0; for(auto a : arr[i]) sum += a - '0';
        switch (l){
            case 1:
                sol += uno[sum];
                break;
            case 2:
                sol += dos[sum];
                break;
            case 3:
                sol += tres[sum];
                sol += uno[sum-2*(arr[i][arr[i].length()-1] - '0')];
                sol += uno[sum-2*(arr[i][0] - '0')];
                break;
            case 4:
                sol += cuatro[sum];
                sol += dos[sum - 2*(arr[i][arr[i].length()-1] - '0')];
                sol += dos[sum-2*(arr[i][0] - '0')];
                break;
            case 5:
                sol += cinco[sum];
                sol += tres[sum-2*(arr[i][arr[i].length()-1] - '0')];
                sol += tres[sum-2*(arr[i][0] - '0')];
                sol += uno[sum-2*(arr[i][arr[i].length()-1] - '0' + arr[i][arr[i].length()-2] - '0')];
                sol += uno[sum-2*(arr[i][0] - '0' + arr[i][1] - '0')];
                break;
        }
    }
    cout << sol << "\n";
}

/*
10
5 93746 59 3746 593 746 5937 46 59374 6
20

5
2 22 222 2222 22222
8

3
1 1 1
9
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}