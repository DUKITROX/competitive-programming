#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int A,B,a,b;
	bucle : while(cin >> A >> B >> a >> b && (A||B||a||b)){
		if(a<b) swap(a,b); if(A<B) swap(A,B);
		if(a==b){
			cout << (A%a==0&&A==B?"SI\n":"NO\n");
			goto bucle;
		}
		int rx = (A*a-B*b) % (a*a-b*b);
		int sy = (B*a-A*b);
		int ry = sy % (a*a-b*b);
		if(sy>=0 && !rx && !ry) cout << "SI\n";
		else cout << "NO\n";
	}
}
