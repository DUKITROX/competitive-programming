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

ll get(vector<ll> &v){
    int n=SZ(v);

    vector<int> lef(n,-1), rig(n,n);

    {
        vector<int> asd;
        fore(i,0,n){
            while(SZ(asd) && v[asd.back()]>v[i]) asd.pop_back();
            if(SZ(asd)) lef[i]=asd.back();
            asd.pb(i);
        }
    }

    {
        vector<int> asd;
        for(int i=n-1;i>=0;i--){
            while(SZ(asd) && v[asd.back()]>=v[i]) asd.pop_back();
            if(SZ(asd)) rig[i]=asd.back();
            asd.pb(i);
        }
    }

    ll ans=0;
    fore(i,0,n) ans+=v[i]*(rig[i]-i)*(i-lef[i]);
    return ans;
}

int main(){FIN;
    int n,m;
    
    while(cin>>n>>m){
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> lef(n, vector<int>(m,1));

        fore(i,0,n) fore(j,0,m) cin>>a[i][j];

        fore(i,0,n) fore(j,1,m) if(a[i][j]==a[i][j-1]) lef[i][j]+=lef[i][j-1];

        ll ans=0;

        fore(j,0,m){
            int p=0;
            while(p<n){
                vector<ll> v;
                int id=p;
                while(id<n&&a[id][j]==a[p][j]) id++;
                fore(i,p,id) v.pb(lef[i][j]);
                ans+=get(v);
                p=id;
            }
        }

        cout<<ans<<"\n";
    }
}
