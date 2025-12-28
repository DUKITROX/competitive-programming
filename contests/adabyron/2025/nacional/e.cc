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
    int n,k;
    while(cin>>n>>k && n && k){
        vector<ll> a(n);
        fore(i,0,n) cin>>a[i];
    
        vector<ll> s(n+1);
        fore(i,1,n+1) s[i]=s[i-1]+a[i-1];
    
        double l=0,r=1e6;
        int it=100;
        while(it--){
            double m=(l+r)/2;
    
            vector<double> v(n+1);
            fore(i,0,n+1) v[i]=1.*s[i]-m*i;
            
            auto pre=v;
            fore(i,1,n+1) pre[i]=min(pre[i-1],pre[i]);
    
            int can=0;
            fore(i,k,n+1) can|=v[i] >= pre[i-k];

            if(can) l=m;
            else r=m;
        }
    
        cout<<fixed<<setprecision(10)<<l<<"\n";
    }
}
