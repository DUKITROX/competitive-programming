#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;
const long long LLINF = 4e18;

bool compute(vi& arr, int n, long long c, int d, int k){
    long long sum = 0;
    k++;
    for(int i = 0; i < d; i++){
        if((i%k) < n)
            sum += arr[i%k];
    }
    if(sum >= c) return true;
    else return false;
}

void solve(){
    long long n,c,d,s=0; cin>>n>>c>>d;
    vi arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());

    for(int i = 0; i < d && i < n; i++) s+=arr[i];

    if(arr[0]*d < c) cout << "Impossible\n";
    else if(s >= c) cout << "Infinity\n";
    else{
        int l = 0, r = d-2, m = (r+l)/2, ans = -1;
        while(l<=r){
            if(compute(arr,n,c,d,m)){
                l = m+1;
                ans = m;
                m = (l+r)/2;
            }else{
                r = m-1;
                m = (l+r)/2;
            }
        }
        cout << ans << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
