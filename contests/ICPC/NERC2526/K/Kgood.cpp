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

typedef unsigned long long u64;
const int N=1010;
int r,c;
char s[N];
u64 f[N][60],g[N][60],h[N][60],f1[60],f2[60];
bool b[N][N],ans[N][N];

namespace SAT2 {
	const int N=2200000;
	VI e[N];
	int n,cnt,dfn[N],low[N],st[N],bel[N],top,ind;
	bool ins[N];
	void init(int ct) {
		n=ct;
		cnt=0;top=0;ind=0;
		rep(i,0,n) e[i].clear();
	}  
	void add(int u,int v) { e[u].pb(v);}
	void tarjan(int u) {
		dfn[u]=low[u]=++ind;
		ins[u]=1;
		st[++top]=u;
		rep(i,0,SZ(e[u])) {
			int v=e[u][i];
			if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
			else if (ins[v]) low[u]=min(low[u],low[v]);
		} 
		if (dfn[u]==low[u]) {
			++cnt;
			while (1) {
				bel[st[top]]=cnt;
				ins[st[top]]=0;
				if (st[top--]==u) break;
			}
		}
	}
	void solve() {
		rep(i,0,n) dfn[i]=0;
		rep(i,0,n) if (!dfn[i]) tarjan(i);
		// bel i>=bel i' ->i'
	}
}


bool solve() {
	scanf("%d%d",&r,&c);
	SAT2::init(2*c);
	int m=(c+63)/64;
	rep(i,0,c) rep(j,0,m+1) f[i][j]=g[i][j]=0;
	rep(i,0,c) g[i][i>>6]|=1ull<<(i&63);
	auto findb=[&](u64* x,vector<int> &b) {
		rep(i,0,m) if (x[i]) {
			u64 y=x[i];
			while (y) {
				int z=__builtin_ctzll(y);
				b.pb(i*64+z);
				y-=1ull<<z;
			}
		}
		return b;
	};
	bool val=true;
	rep(i,0,r) {
		scanf("%s",s);
		rep(j,0,c) {
			b[i][j]=s[j]=='B';
			rep(k,0,m+1) {
				h[j][k]=f[j][k];
				if (j>0) h[j][k]^=g[j-1][k];
				if (j+1<c) h[j][k]^=g[j+1][k];
			}
			h[j][m]^=b[i][j];
		}
		rep(j,0,c) rep(k,0,m+1) f[j][k]=g[j][k],g[j][k]=h[j][k];
		if (i==r-1) break;
		rep(j,1,c) {
			rep(k,0,m+1) {
				f1[k]=f[j-1][k]^g[j][k];
				f2[k]=f[j][k]^g[j-1][k];
			}
			VI b1,b2;
			findb(f1,b1);
			findb(f2,b2);
			assert(SZ(b1)<=1&&SZ(b2)<=1);
			if (b1.empty()&&f1[m]==1) continue;
			if (b2.empty()&&f2[m]==1) continue;
			if (b1.empty()&&b2.empty()) val=false;
			else if (b1.empty()) { // f1[m]==0
				//printf("set [%d] = %d\n",b2[0],f2[m]^1);
				SAT2::add(b2[0]+f2[m]*c,b2[0]+(f2[m]^1)*c);
			} else if (b2.empty()) { // f1[m]==0
				//printf("set [%d] = %d\n",b1[0],f1[m]^1);
				SAT2::add(b1[0]+f1[m]*c,b1[0]+(f1[m]^1)*c);
			} else {
				//printf("set [%d] = %d or [%d] = %d\n",b1[0],f1[m]^1,b2[0],f2[m]^1);
				SAT2::add(b1[0]+f1[m]*c,b2[0]+(f2[m]^1)*c);
				SAT2::add(b2[0]+f2[m]*c,b1[0]+(f1[m]^1)*c);
			}
			// 不能都是 0
		}
	}
	if (!val) return false;
	rep(j,0,c) {
		rep(k,0,m+1) {
			f1[k]=g[j][k];
			if (j>=2) f1[k]^=g[j-2][k];
		}
		VI b;
		findb(f1,b);
		assert(SZ(b)<=2);
		//for (auto x:b) printf("[%d] ",x); printf("%d xor\n",f1[m]);
		if (b.empty()) {
			if (f1[m]==1) return false;
			continue;
		}
		if (SZ(b)==1) {
			SAT2::add(b[0]+(f1[m]^1)*c,b[0]+f1[m]*c);
		} else {
			SAT2::add(b[0],b[1]+f1[m]*c);
			SAT2::add(b[1],b[0]+f1[m]*c);
			SAT2::add(b[0]+c,b[1]+(f1[m]^1)*c);
			SAT2::add(b[1]+c,b[0]+(f1[m]^1)*c);
		}
	}
	SAT2::solve();
	rep(i,0,c) {
		if (SAT2::bel[i+c]==SAT2::bel[i]) return false;
		ans[0][i]=SAT2::bel[i+c]<SAT2::bel[i];
	}
	puts("YES");
	rep(i,1,r) {
		rep(j,0,c) {
			ans[i][j]=b[i-1][j];
			if (i>=2) ans[i][j]^=ans[i-2][j];
			if (j>=1) ans[i][j]^=ans[i-1][j-1];
			if (j+1<c) ans[i][j]^=ans[i-1][j+1];
		}
	}
	rep(i,0,r+1) {
		rep(j,0,c) {
			int b=0;
			if (i>0) b^=ans[i-1][j];
			if (i<r) b^=ans[i][j];
			printf("%d",b);
		}
		puts("");
	}
	rep(i,0,r) {
		rep(j,0,c+1) {
			int b=0;
			if (j>0) b^=ans[i][j-1];
			if (j<c) b^=ans[i][j];
			printf("%d",b);
		}
		puts("");
	}

	/*rep(i,0,r) {
		rep(j,0,c) printf("%d",ans[i][j]);
		puts("");
	}*/
	return true;
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		if (!solve()) puts("NO");
	}
}

