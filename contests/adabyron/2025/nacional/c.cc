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
    int n;
    while(cin>>n && n){
        vector<int> a(n);
        fore(i,0,n) cin>>a[i];

        sort(ALL(a));

        int k=a[0];
        ll INF=1e18;

        vector<ll> d(k, INF);
        d[0]=0;

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;

        q.push({0,0});

        while(SZ(q)){
            int x=q.top().snd;
            ll val=q.top().fst;
            q.pop();
            
            if(d[x]!=val) continue;

            fore(i,0,n){
                int y=(a[i]+x)%k;
                ll w=val+a[i];
                if(w<d[y]) d[y]=w, q.push({w,y});
            }
        }

        int bad=0;
        fore(i,0,k) if(d[i]==INF) bad=1;

        if(bad){
            cout<<"INFINITO\n";
            continue;
        }

        ll bst=-INF;
        fore(i,0,k) bst=max(bst, d[i]-k);

        cout<<bst<<"\n";
    }
}
