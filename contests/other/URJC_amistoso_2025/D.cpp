#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	int ind = -1;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		if(s == "NOR"){
			pq.push({1,++ind});
		}else if(s == "P2W"){
			pq.push({0,++ind});
		}else{
			int c; cin >> c;
			while(c-- && !pq.empty()){
				cout << pq.top().second << " ";
				pq.pop();
			}
			cout << "\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

