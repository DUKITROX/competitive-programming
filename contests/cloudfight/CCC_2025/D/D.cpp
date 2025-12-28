#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while (N--) {
		char c;
		int pos1,pos2,time; cin >> pos1 >> c >> pos2 >> time;	
		int act = 5*(pos1>0?1:-1);

		cout << "0 ";
		if(abs(pos1)<8){
			for(int i = 0; i < abs(pos1)/2; i++){
				cout << act << " ";
				act += (pos1>0?-1:1);
			}
			if(abs(pos1)%2==1) cout << act << " ";
			act -= (pos1>0?-1:1);

			for(int i = 0; i < abs(pos1)/2; i++){
				cout << act << " ";
				act -= (pos1>0?-1:1);
			}
		}else{
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act += (pos1>0?-1:1);
			}
			for(int i = 0; i < abs(pos1)-8; i++){
				cout << act << " ";
			}
			act -= (pos1>0?-1:1);
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act -= (pos1>0?-1:1);
			}
		}
		cout << "0\n";


		act = 5*(pos2>0?1:-1);
		cout << "0 ";
		if(abs(pos2)<8){
			for(int i = 0; i < abs(pos2)/2; i++){
				cout << act << " ";
				act += (pos2>0?-1:1);
			}
			if(abs(pos2)%2==1) cout << act << " ";
			act -= (pos2>0?-1:1);
			for(int i = 0; i < abs(pos2)/2; i++){
				cout << act << " ";
				act -= (pos2>0?-1:1);
			}
		}else{
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act += (pos2>0?-1:1);
			}
			for(int i = 0; i < abs(pos2)-8; i++){
				cout << act << " ";
			}
			act -= (pos2>0?-1:1);
			for(int i = 0; i < 4; i++){
				cout << act << " ";
				act -= (pos2>0?-1:1);
			}
		}
		cout << "0\n";
    }
}

