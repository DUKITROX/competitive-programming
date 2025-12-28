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
        ll a,b,c; cin>>a>>b>>c;
        a*=b;

        if(a%c)cout<<"IMPOSIBLE\n";
        else cout<<a/c<<"\n";
    }
}
