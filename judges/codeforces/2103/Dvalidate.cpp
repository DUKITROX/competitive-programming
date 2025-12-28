#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	vector<int> arr(n),sol(n); 
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++) cin >> sol[i];
	int M = 1 + *max_element(arr.begin(), arr.end());
	int it = 1;
	for(int i = 0; i < sol.size(); i++){
		if(arr[i] != it){
			if(it%2){ // min
				if(i && sol[i-1] < sol[i]) {cout << "error"; return;}
				if(i < sol.size()-1 && sol[i+1] < sol[i]) {cout << "error"; return;}
			}else{ // max
				if(i && sol[i-1] > sol[i]) {cout << "error"; return;}
				if(i < sol.size()-1 && sol[i+1] > sol[i]) {cout << "error"; return;}
			}
		}else{
			if(it%2){ // min
				bool p1=true,p2=true;
				if(i && sol[i-1] < sol[i]) {p1 = false;}
				if(i < sol.size()-1 && sol[i+1] < sol[i]) {p2 = false;}
				if(p1&p2) {cout << "error"; return;}
			}else{ // max
				bool p1=true,p2=true;
				if(i && sol[i-1] > sol[i]) {p1 = false;}
				if(i < sol.size()-1 && sol[i+1] > sol[i]) {p2 = false;}
				if(p1&p2) {cout << "error"; return;}
			}
		}
	}
	cout << "OK";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

