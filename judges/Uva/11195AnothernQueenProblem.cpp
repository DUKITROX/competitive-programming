#include <bits/stdc++.h>
using namespace std;

int n = 1;
int rec(int c, bitset<30>& row, bitset<30>& ld, bitset<30>& rd){
	if(c == n) return 1;
	int res = 0;
	for(int r = 0; r < n; r++){
		if(!row[r] && !ld[r+c] && !rd[c-r+n-1]){
			row[r] = ld[r+c] = rd[c-r+n-1] = true;
			res += rec(c+1, row, ld, rd);
			row[r] = ld[r+c] = rd[c-r+n-1] = false;
		}
	} 
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(n; n < 20; n++){
		bitset<30> row, ld, rd;
		auto start = std::chrono::high_resolution_clock::now();
		cout << "Qunatity for (" << n << ") ; " << rec(0, row, ld, rd) << "\n";
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = duration_cast<std::chrono::microseconds>(stop-start);
		cout << "Duration for (" << n << ") : " << (double)duration.count()/1000000 << "\n" << "\n"; 
	}
}
