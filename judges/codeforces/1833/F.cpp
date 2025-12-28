#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <complex>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;
const int INF = 1e9 + 7;

int inv(int i) {
 return i <= 1 ? i : INF - (long long)(INF/i) * inv(INF % i) % INF;
}
int moduloMultiplication(int a, int b,
                               int mod)
{
    int res = 0; // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b) {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1; // b = b / 2
    }
 
    return res;
}

void solve(){
    int n,m; cin >> n >> m;
    vi aux(n), arr;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        cin >> aux[i];     
        if(mp.find(aux[i]) == mp.end()) mp[aux[i]] = 1;
        else mp[aux[i]]++;
    }
    sort(aux.begin(), aux.end());
    arr.push_back(aux[0]);
    for(int i = 1; i < n; i++)
        if(aux[i] != aux[i-1]) arr.push_back(aux[i]);

    n = arr.size();
    int last, acum, sol = 0;
    bool pos = false;

    for(int i = 0; i <= n-m; i++){
        if(pos){
            if(arr[i+m-2]+1 != arr[i+m-1]){
                i += m - 2; //-2 porque luego i++
                pos = false;
            }else{
                acum = moduloMultiplication(acum,inv(last),INF);
                acum = moduloMultiplication(acum,mp[arr[i+m-1]], INF);
                last = mp[arr[i]];
            }
        }else{
            pos = true;
            last = mp[arr[i]];
            acum = last;
            for(int j = 0; j < m-1; j++){
                acum = moduloMultiplication(acum, mp[arr[i+j+1]], INF);
                if(arr[i+j]+1 != arr[i+j+1]){
                    i += j; //porque luego i++
                    pos = false;
                    break;
                }
            }
        }
        if(pos) sol = (sol+acum)%INF;
    }
    cout << sol << "\n";
}

//for 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)solve();
}