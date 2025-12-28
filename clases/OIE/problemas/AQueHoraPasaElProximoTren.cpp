#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q; while(cin >> n >> q){
        vector<string> arr(n); 
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        /*
        arr = {2, 3, 3, 4, 6, 8, 10}; 

        lower_bound(arr.begin(), arr.end(), 7);
        upper_bound(arr.begin(), arr.end(), 7);
        find
        */



        for(int i = 0; i < q; i++){
            string s; cin >> s;
            auto it = lower_bound(arr.begin(), arr.end(), s);
            if(it == arr.end()) {
                cout << "NO\n";
            }else{
                cout << *it << "\n";
            }
        }
        cout << "---\n";
    }
}
/*
4 2
06:40:30 12:50:00 19:20:00 21:25:00
10:20:00
22:00:00
6 3
00:00:00 09:30:00 16:40:30 17:00:00 20:10:40 22:35:00
20:10:40
20:10:41
08:40:30
*/