#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void solve(){
    int n,S1,S2,s1,s2,A=0,B=0;
    vector<pair<int,int> >arr;
    vector<int> a,b;
    cin >> n >> S1 >> S2;
    s1 = S1; s2 = S2;
    for(int i = 0; i < n; i++){
        arr.push_back(make_pair(0,0));
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), greater<pair<int,int> >());

    for(int i = 0; i < n; i++){
        if(s1 < s2){
            a.push_back(arr[i].second+1);
            A += arr[i].first*s1;
            s1+=S1;
        }else{
            b.push_back(arr[i].second+1);
            B += arr[i].first*s2;
            s2+=S2;
        }
    }
    cout << a.size();
    for(int i = 0; i < a.size(); i++) cout << " " << a[i];
    cout << "\n" << b.size();
    for(int i = 0; i < b.size(); i++) cout << " " << b[i];
    cout << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}