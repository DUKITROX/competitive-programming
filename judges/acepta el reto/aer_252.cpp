#include <iostream>
#include <algorithm>
using namespace std;

static string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}
int main(){
    while(true){
        string str;
        getline(cin, str);
        if(str == "XXX") break;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());

        bool pal = true;
        for(int i = 0; i < str.length();i++){
            if(str[i] <97) str[i] +=32;
            if(str[str.length()-1-i] < 97) str[str.length()-1-i] += 32;

            if(str[i] != str[str.length()-1-i]) pal = false;
        }
        if(pal) cout << "SI"<<endl;
        else cout << "NO" << endl;
    }
    return 0;
}