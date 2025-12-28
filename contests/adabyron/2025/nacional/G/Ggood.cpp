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

const int MAXN=3010, INF=1e9;
int dp[MAXN][MAXN], a[MAXN], b[MAXN], lef[MAXN], rig[MAXN], two;

void remleft(int x){
    two-=lef[x]&&rig[x];
    lef[x]--;
    two+=lef[x]&&rig[x];
}

void putleft(int x){
    two-=lef[x]&&rig[x];
    lef[x]++;
    two+=lef[x]&&rig[x];
}

void putright(int x){
    two-=lef[x]&&rig[x];
    rig[x]++;
    two+=lef[x]&&rig[x];
}

void remright(int x){
    two-=lef[x]&&rig[x];
    rig[x]--;
    two+=lef[x]&&rig[x];
}

int main(){FIN;
    int n,m;
    while(cin>>n){

        memset(lef,0,sizeof(lef));
        memset(rig,0,sizeof(rig));
        two=0;

        fore(i,1,n+1) cin>>a[i];

        cin>>m;
        fore(i,1,m+1) cin>>b[i];

        fore(i,1,m+1) putright(b[i]);
        fore(i,1,n+1) putright(a[i]);

        fore(i,0,n+1){
            if(i){
                remright(a[i]);
                putleft(a[i]);
            }
            
            fore(j,0,m+1){
                if(j){
                    remright(b[j]);
                    putleft(b[j]);
                }

                dp[i][j]=min(i?dp[i-1][j]:INF, j?dp[i][j-1]:INF);
                dp[i][j]+=two;

                if(!i&&!j) dp[0][0]=0;
            }
            
            fore(j,1,m+1) remleft(b[j]), putright(b[j]);
        }

        cout<<dp[n][m]<<"\n";
    }
}
