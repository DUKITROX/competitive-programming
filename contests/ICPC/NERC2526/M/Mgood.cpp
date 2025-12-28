#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
const int inf=(1<<30);
char s[N],t[N];
int dp[N][2];
void solve() {
	scanf("%s",s);
	scanf("%s",t);
	int n=strlen(s);
	dp[0][0]=0;
	dp[0][1]=inf;
	rep(i,1,n+1) {
		dp[i][0]=dp[i][1]=inf;
		int x=s[i-1]-'0',y=t[i-1]-'0';
		rep(px,0,2) rep(py,0,2) {
			dp[i][px^py]=min(dp[i][px^py],dp[i-1][px]+(py!=x)+((px^py)!=y));
		}
	}
	printf("%d\n",min(dp[n][0],dp[n][1]));
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}

