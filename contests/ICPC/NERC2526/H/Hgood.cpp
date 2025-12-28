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
ll a[3],b[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<3;i++)
		cin>>a[i];
	ll v;
	cin>>v;
	for(int i=0;i<3;i++)
	{
		ll g=__gcd(a[i],v);
		b[i]=g-1;
		v/=g;
	}
	if(v==1)
	{
		for(int i=0;i<3;i++)
			cout<<b[i]<<" ";
		cout<<'\n';
	}
	else
		cout<<"-1\n";
	return 0;
}
