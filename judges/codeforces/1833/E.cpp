#include <bits/stdc++.h>
using namespace std;

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
void solve(){
    int n,a,numComps=0,numCicle=0;
    set<pair<int,int> > s;
    cin >> n;
    UFDS ufds(n);

    for(int i = 0; i < n; i++){
        cin >> a; a--;
        if(ufds.find(a) != ufds.find(i)){
            ufds.merge(a,i);
            s.insert(make_pair(a,i));
            s.insert(make_pair(i,a));
        }else if(!s.count(make_pair(a,i)) && !s.count(make_pair(i,a))) numCicle++;
    }
    numComps = ufds.numSets;
    if(numComps > numCicle) numCicle++;
    cout << numCicle << " " << numComps << "\n";
}

int main(){
    int t;cin>>t;while(t--)solve();
    return 0;
}