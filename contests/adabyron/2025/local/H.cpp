#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; while(cin >> n && n){
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i].second >> arr[i].first;
        sort(arr.begin(), arr.end());
        
        int  dia = 0;
        for(int i = 0; i < n; i++){
            int pastillas = max(min(arr[i].second, arr[i].first - dia), 0LL);
            dia += pastillas;
        }

        cout << dia << "\n";
    }
}
/*
3
5 20
7 30
4 10
2
10 15
10 15
0
*/