#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,b,c,f; while(cin >> n >> a >> b){
		f=0;
		multiset<int, greater<int>> s1,s2;
		for(int i = 0; i < a; i++){cin >> c; s1.insert(c);}
		for(int i = 0; i < b; i++){cin >> c; s2.insert(c);}

		while(!s1.empty() && !s2.empty()){
			int sz = min({n, (int)s1.size(), (int)s2.size()});
			int res = 0;
			multiset<int> a1, a2;
			for(int i = 0; i < sz; i++){
				int v1 = *s1.begin(), v2 = *s2.begin();
				s1.erase(s1.begin()); s2.erase(s2.begin());
				int m = min(v1,v2);
				res += m;
				v1-=m; v2-=m;
				if(v1) a1.insert(v1);
				if(v2) a2.insert(v2);
			}
			for(auto e : a1) s1.insert(e);
			for(auto e : a2) s2.insert(e);
			cout << (f++?" ":"") << res ;
		}

		cout << "\n";
	}
}
