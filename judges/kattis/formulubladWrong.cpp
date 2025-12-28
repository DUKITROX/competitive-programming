#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <stack>
#include <string>
#include <iomanip>
#include <set>
#include <map>

#define mp make_pair

using namespace std;
using lli = unsigned long long int;
using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;
using vb = vector <bool>;
using vvi = vector <vector<int>>;
using vvc = vector <vector<char>>;
using vvb = vector <vector<bool>>;
using vpi = vector <pair<int, int>>;
using vps = vector <pair<string, string>>;
using vss = vector <vector<string>>;
using ii = pair <int, int>;
using vii = vector <ii>;

const unsigned long long int INF = numeric_limits<unsigned long long int> :: max();

struct pos {
    int x, y;
};

int minL(vi list) {
    int res = list[0];
    for (int j = 0; j < list.size(); j++)if (list[j] < res)res = list[j];
    return res;
}

int maxL(vi list) {
    int res = list[0];
    for (int j = 0; j < list.size(); j++)if (list[j] > res)res = list[j];
    return res;
}

bool isvocal(char L) {
    L = tolower(L);
    if (L == 'a' || L == 'e')return true;
    if (L == 'i' || L == 'o')return true;
    if (L == 'u')return true;
    return false;
}

ostream& operator<<(ostream& out, const vvi& matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            if (matriz[i][j] == INF)out << "INF" << " ";
            else out << matriz[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

ostream& operator<<(ostream& out, const vector<vector<ii>>& matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz.size(); j++) {
            if (matriz[i][j].first == INF)out << "[INF," << matriz[i][j].second << "] ";
            else out << "[" << matriz[i][j].first << "," << matriz[i][j].second << "] ";
        }
        out << endl;
    }
    return out;
}

void floyd(vvi& adjMat, vvi& camino, int V) { // O(V^3) , inviable a partir de V > 1000
    for (int k = 0; k < V; k++) {  // Recorre Vértices
        for (int i = 0; i < V; i++) {  // Recorre filas
            for (int j = 0; j < V; j++) { // Recorre columnas
                if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j]) {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    camino[i][j] = k;
                }
            }
        }
    }
}

void dijkstra(int s, vi& dist, const vector <vector<ii>>& adjList) { // O[(V+E)*Log(V)] , más o menos O(K*N*LogN) con K constante
    dist.assign(adjList.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({ 0, s });
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto a : adjList[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({ dist[a.second], a.second });
            }
        }
    }
}

long int n, l;

struct tRes {
    int val, peso;
    vector<int> list;

    tRes() {
        val = -1;
        peso = -1;
        list = {};
    }
};

vector<vector<tRes>> dp;

tRes solve(vector<pair<int, int>> forms,int pos,tRes r){
    if (pos >= n)return r;
    if (r.peso > l)return r;
    if (dp[pos][r.peso].val != -1)return dp[pos][r.peso];
    if (r.peso + forms[pos].first <= l) {
        tRes con, sin;
        sin = solve(forms, pos + 1, r);
        r.peso += forms[pos].first;
        r.val += forms[pos].second;
        r.list.push_back(pos);
        con = solve(forms, pos + 1, r);
        if (con.val > sin.val)return dp[pos][con.peso] = con;
        else return dp[pos][r.peso] = sin;
    }
    else return dp[pos][r.peso] = solve(forms, pos + 1, r);
}

int main() {
    cin >> n >> l;
    vector<pair<int, int>> forms(n);
    for (int k = 0; k < n; k++) {
        cin >> forms[k].first >> forms[k].second;
    }
    vector<vector<tRes>> dpCopy(n+1,vector<tRes>(l+1));
    dp = dpCopy;
    tRes ini;
    ini.list = {}, ini.peso = 0, ini.val = 0;
    tRes finl;
    finl = solve(forms, 0, ini);
    cout << finl.list.size() << " " << finl.val << endl;
    for (int l = 0; l < finl.list.size(); l++)cout << finl.list[l] << " ";
    cout << endl;
    return 0;
}




/*
struct tRacist {
    string nom,ape;
    vector<pair<int, int>> times;
    tRacist() {
        nom = "";
        ape = "";
        times = vector<pair<int, int>>(3, { 0,0 });
    }
};

int main() {
    char basura;
    int N,num;
    string bib,nom,apell,tram;
    cin >> N;
    while (N != 0) {
        map <string, tRacist> M = {};
        tRacist aux;
        vector<string> ids(0);
        for (int n = 0; n < N; n++) {
            cin >> nom >> apell >> bib;
            aux.nom = nom;
            aux.ape = apell;
            M.insert({ bib,aux });
            ids.push_back(bib);
        }
        for (int n = 0; n < 3 * N; n++) {
            cin >> bib>>tram;
            if (tram == "S1") {
                cin >> num;
                M[bib].times[0].first = num;
                cin >> basura >> num;
                M[bib].times[0].second = num;
            }
            else if (tram == "S2") {
                cin >> num;
                M[bib].times[1].first = num;
                cin >> basura >> num;
                M[bib].times[1].second = num;
            }
            else {
                cin >> num;
                M[bib].times[2].first = num;
                cin >> basura >> num;
                M[bib].times[2].second = num;
            }
        }
        //orden burbuja++
        bool inter = true;
        int i = 0;
        // Desde el 1º hasta el penúltimo si hay intercambios...
        while ((i < N - 1) && inter) {
            inter = false;
            // Desde el último hasta el siguiente a i...
            for (int j = N - 1; j > i; j--) {
                if (M[ids[j]].ape<M[ids[j+1]].ape) {
                    string tmp;
                    tmp = ids[j];
                    ids[j] = ids[j - 1];
                    ids[j - 1] = tmp;
                    inter = true;
                }
            }
            if (inter) {
                i++;
            }
        }
        //orden burbuja++
        //rankings
        vector<int> rank1(N), rank2(N), rankf(N);



        //rankings
        cout << "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK" << endl;
        for (int k = 0; k < ids.size(); k++) {
            cout << M[ids[k]].ape << ", " << M[ids[k]].nom << "          " << ids[k] << "     "<<M[ids[k]].times[0].first<<" : "<< M[ids[k]].times[0].second << "         " << 2 << "     " << M[ids[k]].times[1].first << " : " << M[ids[k]].times[1].second << "         " << 2<< "     " << M[ids[k]].times[2].first << " : " << M[ids[k]].times[2].second << "         " << 1 << endl;
        }
        cout << endl;
        cin >> N;
    }

    return 0;
}
*/

