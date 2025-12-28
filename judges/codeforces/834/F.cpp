#include <iostream>
#include <set>
using namespace std;

void solve(){
    int n, p, arr[100], cont = 0;
    set<int> s;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for(int i = arr[n-1]; i < p; i++){
        if(!s.count(i)){
            cont++;
            s.insert(i);
        }
    }
    
}

int main(){
    int t; cin >> t; while(t--) solve();
}