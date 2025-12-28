#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1,T2>& p){
	os << "(" << p.first << " " << p.second << ")";
	return os;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v){
	for(int i = 0; i < v.size(); i++)
		os << v[i] << " ";
	os << "\n";
	return os;
}

struct cmp{
	bool operator()(ii p1, ii p2){
		if(p1.second < p2.second) return true;
		if(p1.second == p2.second) return p1.first > p2.first;
		return false;
	}
};

void solve(){
	int n; cin >> n;
	vector<ii> arr(n), res(n);
	vector<pair<ii,ii> swp(n<<1);

	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
		res[i] = arr[i];
		swp[i<<1] = {arr[i], {i,-1}};
		swp[(i<<1)+1] = {arr[i], {i,1}};
	}
	
	sort(swp.begin(), swp.end(), [&](const pair<ii,ii>& p1, const pair<ii,ii>& p2)->bool{
		auto[x1,y1,i1,e1] = p1;
		auto[x2,y2,i2,e2] = p2;
		int l1 = (e1==-1?x1:y1), l2 = (e2==-1?x2:y2);
		if(l1 < l2) return true;
		if(l1 == l2){
			if(e1==-1) return true;
			if(e2==-1) return false;
			return x1 > x2;
		}
		return false;
	});

	set<ii> lr;
	set<ii,cmp> rl;

	for(int i = 0; i < n<<1; i++){
		auto [pos, ind] = swp[i];
		ii low = arr[ind];

		if(!lr.count(arr[ind])){
			lr.insert(arr[ind]);
			rl.insert({arr[ind].second, arr[ind].first});
		}else{
			auto lit = lr.lower_bound(arr[ind]);
			auto rit = rl.lower_bound({arr[ind].second, arr[ind].first});

			if(lit != lr.begin()) --lit;
			if(rit != rl.end()) ++rit;

			res[ind].first = (*lit).first;
			if(rit != rl.end()) res[ind].second = (*rit).first;

			lr.erase(arr[ind]);
			rl.erase({arr[ind].second, arr[ind].first});
		}
	}
	for(int i = 0; i < n; i++){
		//cout << res[i].first - arr[i].first + res[i].second - arr[i].second << "\n";
		cout << res[i] << " : " << arr[i] << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
