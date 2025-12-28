#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<pair<string,double>> arr(n);
	vector<double> m(n),M(n);
	double sumM = 0, summ = 0;
	for(int i = 0; i < n; i++){
		double d; string s; cin >> s >> d;	
		arr[i] = {s,d};
		M[i] = min(100.0, d+0.49);
		m[i] = max(0.0, d-0.5);
		sumM += M[i];
		summ += m[i];
	}
	if(sumM < 100.0 || summ > 100)
		cout << "IMPOSSIBLE\n";
	else{
		for(int i = 0; i < n; i++){
			cout << setprecision(2) << fixed << arr[i].first << " "
			<< max(m[i], 100 - sumM + M[i]) << " "
			<< min(M[i], 100 - summ + m[i]) << "\n";
		}
	}
}
