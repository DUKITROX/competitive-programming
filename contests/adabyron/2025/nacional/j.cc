#include<bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,txhdem=b;i<txhdem;i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef __int128 ll;
typedef pair<int,int> ii;

struct pt{
    ll x,y;
    pt(){}
    pt(ll x, ll y):x(x),y(y){}
    ll norm2(){return *this**this;}
    pt operator +(pt p){return pt(x+p.x, y+p.y);}
    pt operator -(pt p){return pt(x-p.x, y-p.y);}
    pt operator *(ll k){return pt(x*k,y*k);}
    ll operator *(pt p){return x*p.x+y*p.y;}
    ll operator %(pt p){return x*p.y-y*p.x;}
    int left(pt p, pt q){return (q-p)%(*this-p)>0;}
    int left2(pt p, pt q){return (q-p)%(*this-p)>=0;}
    bool operator <(pt p){return x<p.x || (x==p.x && y<p.y);}
    bool operator ==(pt p){return x==p.x&&y==p.y;}
    pt rot(pt p){return pt(*this%p, *this*p);}
};
pt ccw90(1,0);
pt cw90(-1,0);

vector<pt> chull(vector<pt> p){
    sort(ALL(p));
    p.erase(unique(ALL(p)), p.end());
    if(SZ(p)<3)return p;
    vector<pt> r;
    fore(i,0,SZ(p)){
        while(SZ(r)>=2&&r.back().left2(r[SZ(r)-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();

    int k=SZ(r);
    for(int i=SZ(p)-1;i>=0;i--){
        while(SZ(r)>=k+2&&r.back().left2(r[SZ(r)-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

struct pol {
    int n; vector<pt> p;
    pol(){}
    pol(vector<pt> _p){p=_p;n=SZ(p);}

    void normalize() {
        if(p[2].left(p[0],p[1])) reverse(ALL(p));
        int pi=min_element(ALL(p))-p.begin();
        vector<pt> s(n);
        fore(i,0,n) s[i]=p[(pi+i)%n];
        p.swap(s);
    }

    bool seghas(pt a, pt b, pt q){
        // en la linea
        if(q.left(a,b) || q.left(b,a)) return 0;

        if(q.left(a, a+(b-a).rot(ccw90))) return 0;
        if(q.left(b, b+(a-b).rot(ccw90))) return 0;

        return 1;
    }

    bool haslog(pt q){
        if(SZ(p)==1) return q==p[0];
        if(SZ(p)==2) return seghas(p[0],p[1], q);


        if(q.left(p[0],p[1]) || q.left(p.back(),p[0])) return 0;
        int a=1,b=SZ(p)-1;
        while(b-a>1){
            int c=(a+b)/2;
            if(!q.left(p[0],p[c])) a=c;
            else b=c;
        }
        return !q.left(p[a],p[a+1]);
    }
};

int main(){FIN;
    int n,q;
    while(cin>>n>>q && n && q){
        vector<pt> v(n);
        fore(i,0,n){
            long long x; cin>>x; v[i].x=x;
        }

        fore(i,0,n){
            long long y; cin>>y; v[i].y=y;
        }

        v=chull(v);

        pol p(v);
        p.normalize();

        while(q--){
            long long xx,yy; cin>>xx>>yy;
            pt me(xx,yy);

            if(p.haslog(me))cout<<"SI\n";
            else cout<<"NO\n";
        }
        cout<<"---\n";
    }
}
