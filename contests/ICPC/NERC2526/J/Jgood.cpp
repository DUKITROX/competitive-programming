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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef long long db;
const db EPS = 0;
  
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
  
inline int cmp(db a, db b){ return sign(a-b); }
  
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
 
	bool operator<(P p) const { 
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}

	bool operator>(P p) const { 
		int c = cmp(x, p.x);
		if (c) return c == 1;
		return cmp(y, p.y) == 1;
	}
 
	bool operator==(P o) const{
		return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
 
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }
	 
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y,x);}
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
};
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

int cmp_ang(P a,P b) { // -1, 0 , 1
	if (a.quad()!=b.quad()) return a.quad()<b.quad()?1:-1;
	return sign(a.det(b));
}


#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
  
bool chkLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return sign(a1+a2) != 0;
}

bool intersect(db l1,db r1,db l2,db r2){
	if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2); 
	return !( cmp(r1,l2) == -1 || cmp(r2,l1) == -1 );
}
  
bool isSS(P p1, P p2, P q1, P q2){
	return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && 
	crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) <= 0;
}
  
bool isSS_strict(P p1, P p2, P q1, P q2){
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) < 0;
}
  
bool isMiddle(db a, db m, db b) {
	return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}
  
bool isMiddle(P a, P m, P b) {
	return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}
  
bool onSeg(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
}
 
bool onSeg_strict(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && sign((q-p1).dot(p1-p2)) * sign((q-p2).dot(p1-p2)) < 0;
}

//polygon
  
db area(vector<P> ps){
	db ret = 0; rep(i,0,ps.size()) ret += ps[i].det(ps[(i+1)%ps.size()]); 
	return ret;
}
  
int contain(vector<P> ps, P p){ //2:inside,1:on_seg,0:outside
	int n = ps.size(), ret = 0; 
	rep(i,0,n){
		P u=ps[i],v=ps[(i+1)%n];
		if(onSeg(u,v,p)) return 1;
		if(cmp(u.y,v.y)<=0) swap(u,v);
		if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
		ret ^= crossOp(p,u,v) > 0;
	}
	return ret*2;
}
  
vector<P> convexHull(vector<P> ps) {
	int n = ps.size(); if(n <= 1) return ps;
	sort(ps.begin(), ps.end());
	vector<P> qs(n * 2); int k = 0;
	for (int i = 0; i < n; qs[k++] = ps[i++]) 
		while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
		while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	qs.resize(k - 1);
	return qs;
}

vector<P> merge(vector<P> a,vector<P> b) {
	rotate(a.begin(),min_element(a.begin(), a.end()),a.end());
	rotate(b.begin(),min_element(b.begin(), b.end()),b.end());
	if (SZ(a)<SZ(b)) swap(a,b);
	if (SZ(b)==1) {
		for (auto &p:a) p=p+b[0];
		return a;
	}
	vector<P> c;
	int p1=0,p2=0;
	while (p1<SZ(a)||p2<SZ(b)) {
		c.pb(a[p1%SZ(a)]+b[p2%SZ(b)]);
		P d1=a[(p1+1)%SZ(a)]-a[p1],d2=b[(p2+1)%SZ(b)]-b[p2];
		auto dcmp=[&](P d1,P d2) {
			int q1=d1==P(0,0)?2:((sign(d1.x)>0||(sign(d1.x)==0&&sign(d1.y)>0))?0:1);
			int q2=d2==P(0,0)?2:((sign(d2.x)>0||(sign(d2.x)==0&&sign(d2.y)>0))?0:1);
			if (q1!=q2) return cmp(q1,q2);
			else return -sign(d1.det(d2));
		};
		if (p1<SZ(a)&&p2<SZ(b)&&dcmp(d1,d2)==0) {
			p1++;
			p2++;
		} else if (p2==SZ(b)||(p1<SZ(a)&&dcmp(d1,d2)==-1)) {
			p1++;
		} else {
			p2++;
		}
	}
	return c;
}

const db INF = 2e9;
struct CH{
	int n;

	vector<P> ps, lower, upper;

	P operator[](int i){return ps[i];}

	int find(vector<P>&vec, P dir){
		int l=0,r=vec.size();
		while(l+5<r){
			int L = (l*2+r)/3, R = (l+r*2)/3;
			if(vec[L].dot(dir) > vec[R].dot(dir))
				r=R;
			else
				l=L;
		}
		int ret = l; rep(k,l+1,r) if(vec[k].dot(dir) > vec[ret].dot(dir)) ret = k;
		return ret;
	}

	/*
	ps[0] must be the smallest one!
	*/

	void init(vector<P> _ps){
		ps = _ps; n = ps.size();

		rotate(ps.begin(),min_element(ps.begin(), ps.end()),ps.end());

		int at = max_element(ps.begin(), ps.end()) - ps.begin();

		lower = vector<P>(ps.begin(),ps.begin() + at + 1);

		upper = vector<P>(ps.begin()+at,ps.end()); upper.pb(ps[0]);
	}

	int findFarest(P dir){
		if(dir.y > 0 || (dir.y==0 && dir.x > 0)) {
			return ( (int)lower.size() -1 + find(upper,dir)) % n;
		} else {
			return find(lower,dir);
		}
	}

	/*P get(int l,int r,P p1,P p2){
		int sl = crossOp(p1,p2,ps[l%n]);
		while(l+1<r){
			int m = (l+r)>>1;
			if(crossOp(p1,p2,ps[m%n]) == sl) 
				l = m;
			else
				r = m;
		}

		return isLL(p1,p2,ps[l%n],ps[(l+1)%n]);
	}

	vector<P> getIS(P p1,P p2){
		int X = findFarest((p2-p1).rot90());
		int Y = findFarest((p1-p2).rot90());
		if(X > Y) swap(X,Y);
		if(crossOp(p1,p2,ps[X]) * crossOp(p1,p2,ps[Y]) < 0){
			return {get(X,Y,p1,p2),get(Y,X+n,p1,p2)};
		} else {
			return {};
		}
	}*/

	void update_tangent(P p, int id, int&a,int&b){
		if(crossOp(p,ps[a],ps[id]) > 0) a = id;
		if(crossOp(p,ps[b],ps[id]) < 0) b = id;
	}

	void binary_search(int l,int r,P p,int&a,int&b){
		if(l==r) return;
		update_tangent(p,l%n,a,b);
		int sl = crossOp(p,ps[l%n],ps[(l+1)%n]);
		while(l+1<r){
			int m = (l+r)>>1;
			if(crossOp(p,ps[m%n],ps[(m+1)%n]) == sl)
				l=m;
			else
				r=m;
		}
		update_tangent(p,r%n,a,b);
	}

	bool contain(P p){
		if(p.x < lower[0].x || p.x > lower.back().x) return 0;
		int id = lower_bound(lower.begin(), lower.end(),(P){p.x,-INF}) - lower.begin();
		if(lower[id].x == p.x){ 
			if(lower[id].y > p.y) return 0;	
		} else { 
			if(crossOp(lower[id-1],lower[id],p) < 0) return 0; 
		}
		id = lower_bound(upper.begin(), upper.end(),P{p.x,INF},greater<P>()) - upper.begin();
		if(upper[id].x == p.x){
			if(upper[id].y < p.y) return 0;
		} else {
			if(crossOp(upper[id-1],upper[id],p) < 0) return 0;
		}
		return 1;
	}

	bool contain_strict(P p){
		if(p.x < lower[0].x || p.x > lower.back().x) return 0;
		int id = lower_bound(lower.begin(), lower.end(),(P){p.x,-INF}) - lower.begin();
		if(lower[id].x == p.x){ 
			if(lower[id].y >= p.y) return 0;	
			if (id+1<SZ(lower)&&crossOp(lower[id],lower[id+1],p) <= 0) return 0;
		} else { 
			if(crossOp(lower[id-1],lower[id],p) <= 0) return 0; 
		}
		id = lower_bound(upper.begin(), upper.end(),(P){p.x,INF},greater<P>()) - upper.begin();
		if(upper[id].x == p.x){
			if(upper[id].y <= p.y) return 0;
			if (id+1<SZ(upper)&&crossOp(upper[id],upper[id+1],p) <= 0) return 0;
		} else {
			if(crossOp(upper[id-1],upper[id],p) <= 0) return 0;
		}
		return 1;
	}

	bool get_tangent(P p,int&a,int&b){ // b->a
		if(contain(p)) return 0;
		a=b=0;
		int id = lower_bound(lower.begin(), lower.end(),p) - lower.begin();
		binary_search(0,id,p,a,b);
		binary_search(id,lower.size(),p,a,b);
		id = lower_bound(upper.begin(), upper.end(),p,greater<P>()) - upper.begin();
		binary_search((int)lower.size() - 1, (int) lower.size() - 1 + id,p,a,b);
		binary_search((int) lower.size() - 1 + id,(int) lower.size() - 1 + upper.size(),p,a,b);
		return 1;
	}
};

void assert0(bool cond) {
	assert(cond);
}
void assert1(bool cond) {
	if (!cond) {
		while (1);
	}
}
void assert2(bool cond) {
	if (!cond) {
		puts("????");
		exit(0);
	}
}

int n,m;
bool solve() {
	cin>>n;
	vector<P> p1(n);
	rep(i,0,n) cin>>p1[i].x>>p1[i].y;
	cin>>m;
	vector<P> p2(m);
	rep(i,0,m) cin>>p2[i].x>>p2[i].y;
	auto pp1=p1,pp2=p2;
	auto report=[&](P c1,P c2,P d1,P d2) {
		assert0(isSS(c1,c2,d1,d2));
		int idc1=-1,idc2=-1,idd1=-1,idd2=-1;
		rep(i,0,n) if (pp1[i]==c1) idc1=i;
		if (idc1==-1) swap(c1,d1),swap(c2,d2);
		rep(i,0,n) if (pp1[i]==c1) idc1=i;
		rep(i,0,n) if (pp1[i]==c2) idc2=i;
		rep(i,0,m) if (pp2[i]==d1) idd1=i;
		rep(i,0,m) if (pp2[i]==d2) idd2=i;
		assert1(idc1!=-1&&idc2!=-1&&idd1!=-1&&idd2!=-1);
		cout<<idc1+1<<" "<<idc2+1<<" "<<idd1+1<<" "<<idd2+1<<"\n";
	};
	auto h1=convexHull(p1);
	auto h2=convexHull(p2);
	auto nh2=h2;
	for (auto &p:nh2) p=p*(-1);
	auto msum=merge(h1,nh2);
	if (contain(msum,P(0,0))==0) {
		return false;
	}
	if (area(h1)<area(h2)) swap(h1,h2),swap(p1,p2);
	CH H1,H2;
	H1.init(h1); H2.init(h2);
	bool inside=true;
	rep(i,0,SZ(h2)) {
		inside&=H1.contain_strict(h2[i]);
	}
	if (!inside) {
		int i=0,j=0;
		while (1) {
			auto a0=h1[(i-1+SZ(h1))%SZ(h1)];
			auto a1=h1[i];
			auto b0=h2[(j-1+SZ(h2))%SZ(h2)];
			auto b1=h2[j];
			auto pv=a1-a0,qv=b1-b0;
			if (isSS(a0,a1,b0,b1)) {
				report(a0,a1,b0,b1);
				return true;
			}
			if (qv.det(pv)>=0) {
				if (crossOp(b0,b1,a1)>=0) j+=1;
				else i+=1;
			} else {
				if (crossOp(a0,a1,b1)>=0) i+=1;
				else j+=1;
			}
		}
		return false;
	} else {
		for (auto x:p1) if (H2.contain(x)) {
			auto y=h1[0];
			rep(j,0,SZ(h2)) {
				auto p1=h2[j],p2=h2[(j+1)%SZ(h2)];
				if (isSS(x,y,p1,p2)) {
					report(x,y,p1,p2);
					return true;
				}
			}
			assert2(false);
		}

		vector<P> ang;
		vector<pair<P,P>> arc(SZ(p1));
		rep(i,0,SZ(p1)) {
			int c1=-1,c2=-1;
			assert1(H2.get_tangent(p1[i],c1,c2));
			arc[i]=mp((H2[c1]-p1[i]),(H2[c2]-p1[i]));
			swap(arc[i].fi,arc[i].se);
			assert1(arc[i].fi.det(arc[i].se)>=0);
			arc[i].se=arc[i].se.rot90();
			arc[i].fi=(arc[i].fi*(-1)).rot90();
			swap(arc[i].fi,arc[i].se);
			//printf("?? %lld,%lld %lld,%lld\n",arc[i].fi.x,arc[i].fi.y,arc[i].se.x,arc[i].se.y);
			assert1(arc[i].fi.det(arc[i].se)>=0);
			ang.pb(arc[i].fi);
			ang.pb(arc[i].se);
		}
		sort(ang.begin(),ang.end(),[&](P a,P b) {
			return cmp_ang(a,b)>0;
		});
		ang.resize(unique(ang.begin(),ang.end(),[&](P a,P b) {
			return cmp_ang(a,b)==0;
		})-ang.begin());
		int o=SZ(ang);
		vector<PII> mx(2*o+1,mp(5*o,-1));
		vector<PII> pt(SZ(p1));
		//printf("?? %d\n",o);
		rep(i,0,SZ(p1)) {
			pt[i].fi=lower_bound(all(ang),arc[i].fi,[&](P a,P b) {
				return cmp_ang(a,b)>=0;
			})-ang.begin();
			pt[i].se=lower_bound(all(ang),arc[i].se,[&](P a,P b) {
				return cmp_ang(a,b)>=0;
			})-ang.begin();
			//printf("%d %d\n",pt[i].fi,pt[i].se);
			if (pt[i].se<pt[i].fi) pt[i].se+=o;
			mx[pt[i].fi]=min(mx[pt[i].fi],mp(pt[i].se,i));
			mx[pt[i].fi+o]=min(mx[pt[i].fi+o],mp(pt[i].se+o,i));
		}
		per(i,0,2*o) mx[i]=min(mx[i],mx[i+1]);
		rep(i,0,SZ(p1)) if (mx[pt[i].se].fi<=pt[i].fi+o) {
			auto x=p1[i];
			auto y=p1[mx[pt[i].se].se];
			//printf("!! %d %d\n",i,mx[pt[i].se].se);
			assert2(!(x==y));
			rep(j,0,SZ(h2)) {
				auto q1=h2[j];
				auto q2=h2[(j+1)%SZ(h2)];
				if (isSS(x,y,q1,q2)) {
					report(x,y,q1,q2);
					return true;
				}
			}
			assert2(false);
		}
		return false;
	}
}

int _;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

// to test hull 退化成一条线
	for (cin>>_;_;_--) {
		if (!solve()) {
			cout<<"-1\n";
		}
	}
}
