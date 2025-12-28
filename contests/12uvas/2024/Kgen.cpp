#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 40;
	for(int i = 0; i < n; i++){
		cout << "20 " << (rand()%16)+1 << " " << (rand()%16)+1 << " " << (rand()%32)+1 << " " << (rand()%(16*16))+1 << "\n";
	}
}
