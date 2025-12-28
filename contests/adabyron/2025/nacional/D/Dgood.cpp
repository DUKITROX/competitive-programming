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

int ask(ll x){
    cout<<"? "<<x<<endl;
    string s; cin>>s;
    return s=="SI";
}

int main(){FIN;
    ll n;
    while(cin>>n && n){

        ll l=1,r=n,c=0;
        while(l<=r){
            ll m=(l+r)/2;

            if(ask(m*(1ll<<c))) l=m+1,c++;
            else r=m-1;
        }

        cout<<"=> "<<r<<endl;
    }
}
