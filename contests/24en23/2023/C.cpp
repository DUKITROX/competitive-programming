#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
#define first ff
#define second ss
const int INF = 1e9+7;


struct UFDS {
       vector<int>  p, setSize;
       int numSets;
       UFDS( int n ){
	 p.assign(n, 0);
	 setSize.assign(n, 1);
	 numSets = n;
              for(int i = 0; i < n; i++)
                    p[ i ] = i;
       }
       int find(int x){
              return(p[ x ] == x ? x : p[ x ] = find( p[ x ] ) );
       }
       void merge(int x, int y){
              int i = find(x), j = find(y);
	 if(i == j) return;
	 p[ i ] = j;
	 setSize[ j ] += setSize[ i ];
	 numSets--;
       }
       int size(int i){
              return setSize[ find( i ) ];
       }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n){
        int a,b;
        int cont = 0;
        UFDS ufds(n);
        set<ii> s;
        while(cin >> a >> b && (a+b)){
            a--;b--;
            if (ufds.find(a) == ufds.find(b)){
                cont++;
            }else {
                ufds.merge(a,b);
            }
        }
        cout << cont << "\n";
    }
}