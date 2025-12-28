#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; while(cin >> n && n){
		int N = n; while(__builtin_popcount(N)!=1) N++; N *= 1;
		
		vector<int> arr(N,-1); for(int i = 0; i < n; i++) arr[(N/2)+i] = i+1;

		auto l = [](int i)->int{return (i<<1);};
		auto r = [](int i)->int{return (i<<1)+1;};
		auto p = [](int i)->int{return (i>>1);};

		int f,s;
		for(int i = (N/2)-1; i >= 1; i--){
			if(arr[l(i)] == -1) arr[i] = arr[r(i)];
			else if(arr[r(i)] == -1) arr[i] = arr[l(i)];
			else{
				if(arr[l(i)] == arr[r(i)]) arr[i] = arr[l(i)];
				else{
					cout << "? " << arr[l(i)] << " " << arr[r(i)] << endl;
					cin >> arr[i];
				}
			}
		}
		
		f = arr[1]; s = (arr[2]==arr[1]?arr[3]:arr[2]);
		for(int i = 1; i < (N>>1);){
			if((arr[l(i)] == f ? arr[r(i)] : arr[l(i)]) == -1)	{
				i = (arr[l(i)] == f ? l(i) : r(i));
			}else if(s == (arr[l(i)] == f ? arr[r(i)] : arr[l(i)]))
				i = (arr[l(i)] == f ? l(i) : r(i));
			else{
				cout << "? " << s << " " << (arr[l(i)] == f ? arr[r(i)] : arr[l(i)]) << endl;
				cin >> s;
				i = (arr[l(i)] == f ? l(i) : r(i));
			}
		}
		cout << "=> " << f << " " << s << endl;
	}
}
