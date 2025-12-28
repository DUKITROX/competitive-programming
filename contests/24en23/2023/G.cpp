#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
#define first ff
#define second ss
const int INF = 1e9+7;

struct comp{
    bool operator ()(int a, int b){return a<b;}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int F,A,C;
    while(cin >> F >> A >> C){
        priority_queue<int, vector<int>, comp> pq;
        for(int i = 0; i < F; i++){
            int a; cin >> a;
            pq.push(A-a);
        }
        ll cont = 0, aux;
        while(C--){
            aux = pq.top();
            pq.pop();
            cont += aux;
            if(aux) aux--;
            pq.push(aux);
        }
        cout << cont << "\n";
    }
}