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
typedef long double ld;

ld EPS=5e-5;

struct pt{
    ld x,y;
    pt(){}
    pt(ld x, ld y):x(x),y(y){}
    ld norm2(){return *this**this;}
    ld norm(){return sqrtl(norm2());}
    pt operator +(pt p){return pt(x+p.x, y+p.y);}
    pt operator -(pt p){return pt(x-p.x, y-p.y);}
    pt operator *(ld k){return pt(x*k,y*k);}
    pt operator /(ld k){return pt(x/k,y/k);}
    ld operator *(pt p){return x*p.x+y*p.y;}
    pt unit(){return *this/norm();}
};

struct ln{
    pt p,pq;
    ln(){}
    ln(pt p, pt q):p(p),pq(q-p){}

    bool has(pt r){return dist(r)<=EPS;}
    bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
    
    pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
    ld dist(pt r){return (r-proj(r)).norm();}
};

int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        pt p,q; cin>>p.x>>p.y>>q.x>>q.y;

        vector<pt> v(n);
        fore(i,0,n) cin>>v[i].x>>v[i].y;

        int ans=0;

        fore(i,0,n){
            pt a=v[i], b=v[(i+1)%n];

            pt pp=ln(a,b).proj(p);
            pt qq=ln(a,b).proj(q);

            ld da=(p-pp).norm();
            ld db=(q-qq).norm();

            ld propa=da/(da+db);
            pt endp=pp + (qq-pp)*propa;

            if(ln(a,b).seghas(endp)) ans++;

        }

        cout<<ans<<"\n";
    }
}
