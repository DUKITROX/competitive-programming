#include<bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,txhdem=b;i<txhdem;i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ordered_set s;
        int ans=0;
        fore(i,0,n){
            int x; cin>>x;

            if(!SZ(s) || s.find_by_order((i+1)/2-1)->fst<x) ans++;
            s.insert({x,i});
        }
        cout<<ans<<"\n";
    }
}
