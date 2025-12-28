#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

void compute(int n, int k, vi& pos){
    if(k <= n){
        pos.push_back(k-1);
    }else{
        compute(n-1, k-n, pos);
        pos.push_back(n-1);
    }
}

void solve(){
    int n,k; cin >> n >> k;
    vi pos;
    
    if(k==0) for(int i = 0; i < n; i++) cout << "-1 ";
    else{
        if(k <= n){
            k--;
            for(int i = 0; i < k; i++) cout << "-1 ";
            cout << "33 ";
            for(int i = k+1; i < n; i++) cout << "-100 ";
        }else{
            compute(n,k,pos);
            for(int i = 0; i < pos[0]; i++) cout << "-1 ";
            cout << "33 ";
            if(pos.size() == 1){
                for(int i = pos[0]+1; i < n; i++) cout << "-100 ";
            }else{
                for(int i = pos[0]+1; i < pos[1]; i++) cout << "-34 ";
                for(int i = pos[1]; i < n; i++) cout << "100 ";
            }
        }
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}