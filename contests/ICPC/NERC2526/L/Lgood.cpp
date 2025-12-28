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
using ld=long double;
void die(string S){puts(S.c_str());exit(0);}
map<string,int> Mp;
int n,L;
vector<int> vec[100100];
string tp[100100];
ld cost(int x)
{
	if(!x) return 0;
	return x*log2l(x);
}
vector<int> sa,hi,id;
int M;
int tot;
map<int,int> val[400400];
int sum[400400];
int fa[400400];
inline int anc(int x)
{
	while(fa[x]!=x) x=fa[x]=fa[fa[x]];
	return x;
}
int rk[400400*2],y[400400],tmp[400400*2],c[400400];
int mv;
void Sort()
{
	for(int i=1;i<=mv;i++) c[i]=0;
	for(int i=1;i<=L;i++) c[rk[i]]++;
	for(int i=1;i<=mv;i++) c[i]+=c[i-1];
	for(int i=L;i>=1;i--) sa[c[rk[y[i]]]--]=y[i];
}
void get_sa(vector<int> S)
{
	sa=vector<int>(L+1);
	S.insert(S.begin(),0);
	mv=L;
	for(int i=1;i<=L;i++)
	{
		rk[i]=S[i];
		y[i]=i;
	}
	Sort();
	for(int k=1;k<=L;k<<=1)
	{
		int ret=0;
		for(int i=L-k+1;i<=L;i++) y[++ret]=i;
		for(int i=1;i<=L;i++) if(sa[i]>k) y[++ret]=sa[i]-k;
		Sort();
		for(int i=1;i<=L;i++) swap(rk[i],tmp[i]);
		rk[sa[1]]=1;
		int num=1;
		for(int i=2;i<=L;i++)
		{
			if(tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+k]==tmp[sa[i-1]+k])
				rk[sa[i]]=num;
			else
				rk[sa[i]]=++num;
		}
		mv=num;
	}
	sa.erase(sa.begin());
	for(auto &x:sa) x--;
}
void get_hi(vector<int> S)
{
	hi=vector<int>(L);
	int k=0;
	for(int i=0;i<L;i++)
	{
		if(!id[i]) continue;
		int j=sa[id[i]-1];
		if(k) k--;
		while(i+k<L&&j+k<L&&S[i+k]==S[j+k]) k++;
		hi[id[i]]=k;
	}
}
int st[20][400400];
int lcp(int l,int r)
{
	l=id[l];
	r=id[r];
	if(l>r) swap(l,r);
	int x=__lg(r-l);
	return min(st[x][l+1],st[x][r-(1<<x)+1]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int tot=0;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		M=max(m,M);
		for(int j=0;j<m;j++)
		{
			string token;
			cin>>token;
			if(!Mp[token]) Mp[token]=++tot;
			int id=Mp[token];
			vec[i].pb(id);
		}
		cin>>tp[i];
	}
	vector<int> S;
	for(int i=0;i<n;i++)
	{
		for(int j=sz(vec[i])-1;j>=0;j--)
			S.pb(vec[i][j]);
		S.pb(++tot);
	}
	// getsa, gethi
	L=sz(S);
	get_sa(S);
	id=vector<int>(L);
	for(int i=0;i<L;i++)
		id[sa[i]]=i;
	get_hi(S);
	for(int i=0;i<L;i++)
		st[0][i]=hi[i];
	for(int i=1;i<20;i++)
		for(int j=0;j+(1<<i)<=L;j++)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=0;i<L;i++)
		fa[i]=i;
	vector<pii> vec;
	for(int i=1;i<L;i++)
		vec.pb(hi[i],i);
	rsrt(vec);
	int po=0;
	ld total=0;
	vector<ld> Ans;
	int cur=0;
	vector<int> posl(L,-1);
	for(int i=0;i<n;i++)
	{
		int m=sz(::vec[i]);
		for(int j=0;j<m;j++) if(tp[i][m-1-j]=='L')
		{
			int label=::vec[i][m-1-j];
			val[id[cur+j+1]][label]=1;
			sum[id[cur+j+1]]=1;
			posl[id[cur+j+1]]=m-1-j;
		}
		cur+=m+1;
	}
	auto merge=[&](int u)
	{
		int A=anc(u);
		int B=anc(u-1);
		if(A==B) return ;
		if(sz(val[A])>sz(val[B])) swap(A,B);
		total-=cost(sum[A]);
		total-=cost(sum[B]);
		sum[B]+=sum[A];
		total+=cost(sum[B]);
		for(auto [lab,cc]:val[A])
		{
			total+=cost(cc);
			total+=cost(val[B][lab]);
			val[B][lab]+=cc;
			total-=cost(val[B][lab]);
		}
		map<int,int>().swap(val[A]);
		sum[A]=0;
		fa[A]=B;
	};
	auto merge2=[&](int A,int B)
	{
		A=anc(A);
		B=anc(B);
		if(A==B) return ;
		if(sz(val[A])>sz(val[B])) swap(A,B);
		total-=cost(sum[A]);
		total-=cost(sum[B]);
		sum[B]+=sum[A];
		total+=cost(sum[B]);
		for(auto [lab,cc]:val[A])
		{
			total+=cost(cc);
			total+=cost(val[B][lab]);
			val[B][lab]+=cc;
			total-=cost(val[B][lab]);
		}
		map<int,int>().swap(val[A]);
		sum[A]=0;
		fa[A]=B;
	};
	vector<int> lst(M,-1);
	for(int i=0;i<L;i++)
		if(~posl[i])
		{
			if(~lst[posl[i]])
				if(lcp(sa[lst[posl[i]]],sa[i])>=posl[i])
					merge2(lst[posl[i]],i);
			lst[posl[i]]=i;
		}
	for(int Len=M-1;Len>=0;Len--)
	{
		while(po<sz(vec)&&vec[po].first>=Len)
		{
			int id=vec[po++].second;
			merge(id);
		}
		Ans.pb(total);
	}
	rev(Ans);
	cout<<fixed<<setprecision(12);
	for(auto ans:Ans)
		cout<<ans<<'\n';
	return 0;
}
