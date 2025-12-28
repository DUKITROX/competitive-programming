#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int INF = 1e9;

struct UFDS{
    int numSets;
    vi p, setSize;
    UFDS(int n){
        numSets = n;
        p.assign(n,0);
        setSize.assign(n,1);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){
        return (p[x] == x ? x : p[x] = find(p[x]));
    }
    void merge(int x , int y){
        int i = find(x), j = find(y);
        if(i == j) return;
        p[i] = j;
        setSize[j] += setSize[i];
        numSets--;
    }
    int getSize(int x){
        int i = find(x);
        return setSize[i];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        UFDS sd(n);
        while(m--){
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            sd.merge(a,b);
        }
        int f=0;
        for(int i = 0; i < n; i++) f = max(f, sd.getSize(i));
        cout << f << "\n";
    }
    return 0;
}




/*#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int> > const& adyList, vector<bool>& visited, int pos){
    visited[pos] = true;
    int res = 1;
    for(int i = 0; i < adyList[pos].size(); i++){
        if(!visited[adyList[pos][i]]) res += DFS(adyList, visited, adyList[pos][i]);
    }
    return res;
}

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c < casos; c++){
        int N, M;
        cin >> N >> M;
        vector<vector<int> > tablaAdyacencia(N+1);
        int n1, n2;
        for(int i = 0; i < M; i++){
            cin >> n1 >> n2;
            tablaAdyacencia[n1].push_back(n2);
            tablaAdyacencia[n2].push_back(n1);
        }
        int sol = 0, aux;
        vector<bool> visited(N+1);
        for(int i = 1; i <= N; i++){
            if(!visited[i]) aux = DFS(tablaAdyacencia, visited, i);
            if(aux > sol) sol = aux;
        }
        cout << sol << endl;
    }
    return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int> > const& adyList, vector<bool>& visited, int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int tot = 1,act;
    while(!q.empty()){
        act = q.front();
        q.pop();
        for(int i = 0; i < adyList[act].size(); i++){
            if(!visited[adyList[act][i]]){
                visited[adyList[act][i]] = true;
                q.push(adyList[act][i]);
                tot++;
            }
        }
    }
    return tot;
}

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        int v, r;
        cin >> v >> r;
        vector<vector<int> > adyList(v);
        vector<bool> visited(v, false);
        int n1,n2;
        for(int i = 0; i < r; i++){
            cin >> n1 >> n2;
            adyList[n1-1].push_back(n2-1);
            adyList[n2-1].push_back(n1-1);
        }
        int cant, max =0;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                cant = BFS(adyList, visited, i);
            }
            if (cant > max) max = cant;
        }
        cout << max << endl;
    }
    return 0;
}
*/