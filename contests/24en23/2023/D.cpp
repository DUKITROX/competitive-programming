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
    int c,d,n;
    while(true){
        cin >> c;
        if(!cin) break;
        cin >> d >> n;
        bool pos = true;
        int ant, act;
        cin >> ant;
        vi arr(n);
        for(int i = 0; i < n; i++){
            cin >> act;
            arr[i] = act-ant;
            ant = act;
        }
        ant = arr[0];
        int m = ant, M = ant;
        for(int i = 1; i < n; i++){
            act = arr[i];
            if(abs(act-ant) > c) pos = false;
            M = max(M, act);
            m = min(m, act);
            if(abs(M-m) > d) pos = false;
            ant = act;
        }
        if(pos) cout << "Ok\n";
        else cout << "Tropiezo\n";
    }
}