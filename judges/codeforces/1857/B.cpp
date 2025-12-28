#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){cout << arr[0]; for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    string s; cin >> s;
    int k=s.length()+1;
    for(int i = s.length()-1; i > 0; i--){
        if(s[i]-'0' == 9){
            while(s[i]-'0' == 9 && i > 0)i--;
            s[i]++;
            k = i;
            i++;
        }else if(s[i]-'0' >= 5){
            if(s[i-1] != '9') s[i-1]++;
            k = i-1;
        }
    }
    if(s[0]-'0' >= 5){
        cout << "1";
        k = -1;
    }
    for(int i = 0; i < s.length(); i++){
        if(i > k)cout << "0";
        else cout << s[i];
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}