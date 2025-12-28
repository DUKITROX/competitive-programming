#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    
}
int main(){
    const int N = 9;
    int a[N] = {1,2,5,7,8,23,65,66,67};
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(j!=i)sum+=a[i];
        }
        cout << i+1 << " : " << a[i]*sum << endl;
    }
}
