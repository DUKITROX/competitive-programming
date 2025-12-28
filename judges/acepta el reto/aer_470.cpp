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

int semiLast(set<int>& s){
    set<int>::iterator it = s.end();
    it--;
    return *it;
}
int last(set<int>& s){return *(s.rbegin());}

void solve(string s){
    int cont = 0;
    int a=0,b=1,c=2;
    set<int> pos; for(int i = 0; i < 3; i++) pos.insert(i);
    while(c < s.length()){
        if(s[a]=='R' && s[b]=='A' && s[c]=='V'){
            cont++;
            /*
            cout << a << " " << b << " " << c << "\n";
            for(auto v : pos) cout << v << " ";
            cout << "\n";
            */
            pos.erase(a);pos.erase(b);pos.erase(c);
            if(pos.size() > 1){
                a = semiLast(pos); b = last(pos); c++;
                pos.insert(c);
            }else if(pos.size()==1){
                a = last(pos);b=c;c++;
                pos.insert(c);
            }else{
                a=c+1;b=a+1;c=b+1;
                pos.insert(a);pos.insert(b);pos.insert(c);
            }
        }else {
            a=b;b=c;c++;
            pos.insert(c);
        }
        if(a<0) a=c;b=a+1;c=b+1;
    }
    cout << cont << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; while(cin >> s)solve(s);
}
