#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

void solve(){
    int n;
    string s; cin >> n >> s; string a = "";
    a += s[0];
    char c = s[0];
    for(int i = 1; i < n-1; i++){
        if(s[i] == c){
            c = s[i+1];
            a += c;
            i++;
        }
    }
    cout << a <<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}