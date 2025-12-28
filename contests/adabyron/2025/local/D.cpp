#include <bits/stdc++.h>
using  namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "C"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string roman;
    for (auto &[value, symbol] : values) {
        while (num >= value) {
            roman += symbol;
            num -= value;
        }
    }
    return roman;
}

int main(){
	set<string> wrds;
	for(int i = 1; i <= 3000; i++){
		if(intToRoman(i).size())
	}
	string s; while(cin >> s && s != "ZZZ"){
		if(wrds.count(s))
			cout << "SI\n";
		else{
			cout << "NO " << (wrds.upper_bound(s) == wrds.end() ? "" : *(wrds.upper_bound(s))) << "\n";
		}
	}
}
