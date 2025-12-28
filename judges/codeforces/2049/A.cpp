#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
template <typename T> istream& operator>>(istream& is, vector<T>& v){
	for(int i = 0; i < v.size(); i++) is >> v[i];
	return is;
}

void solve(){
	int n; cin >> n; vi arr(n); cin >> arr;
	bool totC=true,ab=arr[0]!=0;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(arr[i]) totC = false;
		if(!arr[i] && ab){ count++; ab = false;}
		if(arr[i]) ab = true;
		if(!arr[i]) ab = false;
	}
	if(arr[n-1]) count++;
	if(totC) cout << "0\n";
	else cout << min(count,2) <<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
