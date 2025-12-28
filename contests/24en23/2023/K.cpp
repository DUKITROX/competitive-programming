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

void solve(){
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n){
        vi arr;
        int cero=0;
        while(n){
            if(n%10==0)cero++;
            arr.push_back(n%10);
            n/=10;
        }
        int N=0, m=0;
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i];
            N += arr[i]*pow(10,arr.size()-i-1);
        }
        cout << " - ";
        sort(arr.begin(), arr.end());
        for(int i = cero; i < arr.size(); i++){
            cout << arr[i];
            m += arr[i]*pow(10,arr.size()-i-1);
        }
        cout << " = " << N-m << " = " << (N-m)/9 << " x 9\n";
    }
}