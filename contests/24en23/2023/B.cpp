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

ll countDigit(ll n) { 
  return floor(log10(n) + 1); 
}
bool check(ll a, ll b){
    bool ok = true;
    vector<ll> nums(10, 0);
    while(a){
        nums[a%10]++;
        a /= 10;
    }
    while(b){
        nums[b%10]++;
        b /= 10;
    }
    for(int i = 1; i < 10; i++){
        if(nums[i] != 1) ok = false;
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll A,B;
    while(cin >> A >> B && (A+B)){
        ll a=2*A,b=2*B;
        ll cont = 0;
        ll mult = 3;
        while(countDigit(a) + countDigit(b) <= 9){
            if(countDigit(a) + countDigit(b) == 9 && check(a,b)) cont++;
            a = A*mult;
            b = B*mult;
            mult++;
        }
        cout << cont << "\n";
    }
}