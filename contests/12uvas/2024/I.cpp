#include <bits/stdc++.h>
using namespace std;

void merge(int n1, int n2, map<int,int>& m){
	bool elim = false;

	auto it1 = m.lower_bound(n1);
	if(it1 != m.end() && (*it1).first <= n2+1){
		int aux = (*it1).second;
		m.erase(it1);
		m[n1] = aux;
		n2 = aux;
		elim = true;
	}

	auto it2 = m.lower_bound(n1);
	if(it2 != m.begin()){
		it2 = prev(it2);

		if((*it2).second+1 >= n1){
			if(elim) m.erase(m.lower_bound(n1));
			elim = true;
			m[(*it2).first] = n2;
		}
	}

	if(!elim) m[n1] = n2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cont = 1;
	int a,b; while(cin >> a >> b && (a||b)){
		vector<pair<int,int>> arr;
		for(int i = 0; i < b; i++){
			int n; cin >> n;
			for(int j = 0; j < n; j++){
				string s; cin >> s;
				int n1 = stoi(s.substr(0, s.find(',')));
				int n2 = stoi(s.substr(s.find(',')+1));
				
				arr.push_back({n1,-1});
				arr.push_back({n2+1,1});
			}
		}

		sort(arr.begin(), arr.end());
		int cont = 0; bool pos = arr.size()!=0;
		for(int i = 0; i < arr.size(); i++){
			cont -= arr[i].second;
			if(cont<=0 && i != arr.size()-1) pos = false;
		}
		if(arr.size()) pos &= (arr[0].first == 1);
		if(arr.size()) pos &= (arr[arr.size()-1].first > a);

		cout << (pos?"SI":"NO") << "\n";
	}
}
