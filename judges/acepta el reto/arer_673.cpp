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

/*
4 2
1 2 2 1
*/

void solve(int n, int c){
    vi sums(n,0);
    if(!cin) return;
    for(int i = 0; i < n; i++){
        cin >> sums[i];
        if(i) sums[i] += sums[i-1];
    }
    int ind = 0, M = -INF;
    //show(sums);
    for(int i = c-1; i < n; i++){
        int sum, val;
        if(i!=c-1){
            sum = sums[i]-sums[i-c];
            val = sum/2 + sums[i-c];
        }else{
            sum = sums[i];
            val = sum/2;
        }
        auto v = lower_bound(sums.begin()+i-c+1, sums.begin()+i, val);
        //cout << sum << " " << val << " " << *v << "\n";
        if(!sum % 2 && v != sums.end() && *v == val && sum > M){
            ind = i-c+2;
            M = sum;
        }
    }
    if(ind) cout << ind << "\n";
    else cout << "SIN ADORNOS\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,c;
    while(cin >> n >> c)solve(n,c);
}