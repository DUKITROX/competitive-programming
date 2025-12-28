#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin >> k;
    vector<int> arr;
    while(k > 0){
        arr.push_back(k%9);
        k/=9;
    }
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) cout << ((arr[i]<4) ? arr[i] : arr[i]+1);
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}