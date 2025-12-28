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

const int MAXN=1e7+1;
int spf[MAXN],p[MAXN], am;
ll s[MAXN];

int main(){FIN;
    fore(i,2,MAXN) if(!spf[i]){
        p[am++]=i;
        s[am]=s[am-1]+p[am-1];
        for(ll j=1ll*i*i;j<MAXN;j+=i) spf[j]=i;
    }

    ll x;
    while(cin>>x && x){
        int l=-1,r=-1;

        int ps=0;
        fore(i,0,am){
            while(ps<=am && s[ps]<s[i]+x) ps++;

            if(ps<=am && s[ps]==s[i]+x && l<0 && ps-i>1){
                l=i+1;
                r=ps;
                break;
            }
        }

        if(l<0) cout<<"NO\n";
        else cout<<p[l-1]<<" "<<p[r-1]<<"\n";
    }
}
