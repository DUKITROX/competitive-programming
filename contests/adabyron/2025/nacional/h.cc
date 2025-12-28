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

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<ii> v(m);
        fore(i,0,m){
            int l,r; cin>>l>>r; l--; r--;
            v[i]={l,r};
        }

        vector<int> ans(n);
        fore(x,0,n){
            int p=x;
            for(auto asd:v){
                if(asd.fst==p) p=asd.snd;
                else if(asd.snd==p) p=asd.fst;
            }
            ans[p]=x;
        }

        fore(i,0,n)cout<<ans[i]+1<<" \n"[i+1==n];
    }
}
