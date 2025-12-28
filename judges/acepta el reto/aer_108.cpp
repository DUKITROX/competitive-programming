#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	while(true){
		double D=0,A=0,M=0,I=0,C=0;
		int tot=0, cc=0;
		char c;
		double d,suma=0;

		cin >> c;
		if(cin.fail()) break;
		cin >> d;
		double max = 0, min = 99999999;
		bool empt = true, t=true;
		char xd,dx;
		while(true){
			if(c == 'N' && d == 0) break;
			if(c == 'D') {
				D+=d;
				if(D > max){
					xd = 'D';
					max = D;
					empt = false;
				}else if(D==max) empt = true;
			}
			else if(c=='A'){
				cc++;
				A+=d;
				if(A > max){
					xd = 'A';
					max = A;
					empt = false;
				}else if(A == max) empt = true;
			}
			else if(c=='M'){
				M+=d;
				if(M > max){
					max = M;
					xd = 'M';
					empt = false;
				}else if(M==max) empt = true;
			}
			else if(c=='I'){
				I+=d;
				if(I > max){
					xd = 'I';
					max = I;
					empt = false;
				}else if ( I == max) empt = true;
			}
			else{
				C+=d;
				if(C > max){
					xd = 'C';
					empt = false;
					max = C;
				}else if(C==max) empt = true;
			}
			tot++;
			suma+=d;
			cin >> c >> d;
		}
		vector<double> f(5);
		f[0]=D;
		f[1]=A;
		f[2]=M;
		f[3]=I;
		f[4]=C;
		sort(f.begin(), f.end());
		if(f[0] == D)dx='D';
		else if(f[0]==A)dx='A';
		else if(f[0]==M)dx='M';
		else if(f[0]==I)dx='I';
		else dx = 'C';

		if(f[3]==f[4]) cout << "EMPATE";
		else if(xd == 'D') cout << "DESAYUNOS";
		else if(xd == 'A')cout << "COMIDAS";
		else if(xd == 'M') cout << "MERIENDAS";
		else if(xd == 'I') cout << "CENAS";
		else cout << "COPAS";
		cout << "#";
		if(f[0]==f[1])cout << "EMPATE";
		else if(dx == 'D') cout << "DESAYUNOS";
		else if(dx == 'A')cout << "COMIDAS";
		else if(dx == 'M') cout << "MERIENDAS";
		else if(dx == 'I') cout << "CENAS";
		else cout << "COPAS";
		cout << "#";
		if(A/cc > suma/tot)cout<<"SI";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}