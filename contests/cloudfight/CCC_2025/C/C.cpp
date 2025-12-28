#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while (N--) {
		int pos,time; cin >> pos >> time;	
		int act = 5*(pos>0?1:-1);

		cout << "0 ";
		if(abs(pos)<8){
			for(int i = 0; i < abs(pos); i++) cout << act << " ";
		}else{
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act += (pos>0?-1:1);
			}
			for(int i = 0; i < abs(pos)-8; i++){
				cout << act << " ";
			}
			act -= (pos>0?-1:1);
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act -= (pos>0?-1:1);
			}
		}
		cout << "0\n";
    }
}

