#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define pi acos(-1.0)
#define mp make_pair
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	Point (const P& p) : x(p.x), y(p.y) {}
	P& operator=(const P& p) {x = p.x; y = p.y; return *this;}
	void adj(){if(y<0){x=-x;y=-y;}}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return abs(sqrt((double)dist2())); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); } // 1(left) 0(middle) -1(right)

void solve(){
	int n; cin >> n;
	vector<pair<Point<double>,int>> arr(n);
	vector<Point<double>> pts(n);
	for(int i = 0; i < n; i++){
		double x,y; cin >> x >> y; arr[i].first = Point{x,y}; cin >> arr[i].second;
		pts[i] = arr[i].first;
	}

	long long sol = 1e18;
	for(int i = 0; i < n; i++){
		Point<double> piv = pts[i];
		sort(arr.begin(), arr.end(), [&](pair<Point<double>,int>& e1, pair<Point<double>,int>& e2)->bool{
			if(e1.first == piv) return true;
			Point<double> p1 = e1.first - piv;
			Point<double> p2 = e2.first - piv;
			p1.adj(); p2.adj();
			return p1.cross(p2) > 0;
		});
		long long A = 0, B = 0;
		for(int j = 2; j < n; j++){
			int cant = arr[j].second*sgn(piv.cross(arr[1].first, arr[j].first));
			if(cant > 0) A += cant;
			else B -= cant;
		}
		sol = min(sol, abs(A-B));
 
		auto act = [&](pair<Point<double>,int> old, pair<Point<double>,int> neww) -> void{
			B += old.second;
			if((old.first-piv).cross(neww.first-piv) < 0){
				B -= neww.second;	
				swap(A,B);
			}else{
				A -= neww.second;
			}
			sol = min(sol, abs(A-B));
		};
		for(int j = 2; j < n; j++) act(arr[j-1], arr[j]);
	}
	cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
