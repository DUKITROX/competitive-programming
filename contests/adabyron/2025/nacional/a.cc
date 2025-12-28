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

const int MAXN=210;
vector<int> g[MAXN];
int mat[MAXN]; bool vis[MAXN];
int match(int x){
    if(vis[x])return 0;
    vis[x]=1;
    for(int y:g[x]) if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
    return 0;
}

int max_matching(int n){
    int r=0;
    fore(i,0,n) mat[i]=-1;
    memset(mat,-1,sizeof(mat));
    fore(i,0,n){
        fore(x,0,n) vis[x]=0;
        match(i);
    }
    fore(i,0,n) if(mat[i]>=0) r++;
    return r;
}

int ds[MAXN][MAXN], INF=1e9;

void floyd(int n){
    fore(k,0,n) fore(i,0,n) fore(j,0,n) ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
}

int main(){FIN;
    int n,m;
    while(cin>>n>>m){

        fore(i,0,n) fore(j,0,n) ds[i][j]=i==j?0:INF;

        fore(i,0,m){
            int x,y,w; cin>>x>>y>>w; x--; y--;
            ds[x][y]=min(ds[x][y],w);
            ds[y][x]=min(ds[y][x],w);
        }

        floyd(n);

        int am=0;
        vector<vector<int>> v(n), wh(n);

        fore(i,0,n){
            int k; cin>>k;
            fore(j,0,k){
                int x; cin>>x;
                wh[i].pb(am++);
                v[i].pb(x);
            }
        }

        fore(i,0,n) fore(j,0,SZ(v[i])) fore(x,0,n) fore(y,0,SZ(v[x])) {
            //(i,j) -> (x,y)

            if(i==x&&j==y)continue;

            if(v[x][y]-v[i][j] >= 2+ds[i][x]){
                g[wh[i][j]].pb(wh[x][y]);
            }
        }

        int res=max_matching(am);
        cout<<am-res<<"\n";


        fore(i,0,am) g[i].clear();
    }
}
