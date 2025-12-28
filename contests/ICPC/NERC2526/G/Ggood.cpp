//Author: Kevin
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define pb emplace_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using i128=__int128_t;
void die(string S){puts(S.c_str());exit(0);}
ll a[500500];
int n;
ll b[500500];
bool check(ll mid)
{
	for(int i=1;i<=n;i++)
	{
		b[i]=mid*2-a[i];
		if(b[i]<0) return false;
	}
	ll tot=0;
	for(int i=1;i<=n;i++)
		tot+=b[i];
	if(tot%2) return false;
	if(tot/2<mid) return false;
	ll v=0;
	ll s=1;
	ll L=0,R=mid;
	for(int i=1;i<=n;i++)
	{
		s=-s;
		v=b[i]-v;
		if(s==1)
		{
			L=max(L,-v);
			R=min(R,mid-v);
		}
		else
		{
			R=min(R,v);
			L=max(L,v-mid);
		}
	}
	if(s==1)
	{
		if(v!=0) return false;
		if(L>R) return false;
		return true;
	}
	else
	{
		if(v%2) return false;
		v/=2;
		if(v<0) return false;
		if(v<L||v>R) return false;
		return true;
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll L=0,R=1e10;
	while(L<R)
	{
		ll mid=(L+R)/2;
		if(check(mid))
			R=mid;
		else
			L=mid+1;
	}
	cout<<L<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
