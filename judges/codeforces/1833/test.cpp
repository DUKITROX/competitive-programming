#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int,int> mp;
    mp.insert(make_pair(0,2));
    cout << mp[0] << endl;
    cout << mp[1] << endl;
    mp[1]++;
    cout << mp[1] << endl;
    mp[1]++;
    cout << mp[1] << endl;
}