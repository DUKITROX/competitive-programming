#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().
count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

template<class T>bool ckmin(T&a,const T&b){return b<a?a=b,1:0;}
template<class T>bool ckmax(T&a,const T&b){return a<b?a=b,1:0;}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
