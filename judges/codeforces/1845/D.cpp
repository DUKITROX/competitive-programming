#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
#define first ff
#define second ss
const int INF = 1e9+7;

ll kadane(vector<ll>& arr){
    ll localMax = 0, globalMax = 0, L=0, ansL=0;
    for(int i = 0; i < arr.size(); i++){
        if(localMax + arr[i] > 0) localMax += arr[i];
        else{
            localMax = 0;
            L = i+1;
        }
        if(localMax > globalMax){
            globalMax = localMax;
            ansL = L;
        }
    }
    if(ansL < arr.size()) return ansL;
    else return 1LL;
}

void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    vector<ll> prefixSums(n,0);
    for(int i = 0; i < n; i++){
        cin >> prefixSums[i];
        arr[i] = -prefixSums[i];
        if(i) prefixSums[i] += prefixSums[i-1];
    }
    ll ind = kadane(arr);
    if(ind == 0 || prefixSums[ind-1] < 0) cout << "0\n";
    else cout << prefixSums[ind-1] << "\n";
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}