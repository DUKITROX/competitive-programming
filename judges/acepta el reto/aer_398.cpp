#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

int manhattanDistance(ii p1, ii p2){return abs(p1.first-p2.first) + abs(p1.second-p2.second);}

const int MAX_N = 102;
int N;
vii pts(MAX_N);

int dp(int num, int n1, int n2, int t1, int t2, map<pair<ii,ii>, int>& memo){
    ii r1 = pts[n1], r2 = pts[n2]; int T,R;
    bool bothZero = false;
    if(t1){
        T = t1;
        R = 0;
    }else if(t2){
        T = t2;
        R = 2;
    }else{
        bothZero = true;
    }
    if(memo.find(make_pair(make_pair(n1,n2), make_pair(T,R))) != memo.end()) return memo[make_pair(make_pair(n1,n2), make_pair(T,R))];
    if(num == N) return max(manhattanDistance(r1,pts[num+1])-t2, manhattanDistance(r2,pts[num+1])-t1);

    int T1 = max(0, manhattanDistance(r1, pts[num+1]) - t2);
    int ans1 = dp(num+1, num+1, n2, t1+T1, 0, memo) + T1;

    int T2 = max(0, manhattanDistance(r2, pts[num+1]) - t1);
    int ans2 = dp(num+1, n1, num+1, 0, T2+t2, memo) + T2;

    if(bothZero) memo[make_pair(make_pair(n1,n2), make_pair(T,0))] = memo[make_pair(make_pair(n1,n2), make_pair(T,1))] = min(ans1,ans2);
    else memo[make_pair(make_pair(n1,n2), make_pair(T,R))] = min(ans1,ans2);
    return min(ans1,ans2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int F,C; cin >> F >> C >> N;
        if(!cin) break;
        pts[0] = make_pair(1,1);   
        for(int i = 1; i <= N; i++) cin >> pts[i].first >> pts[i].second;
        pts[N+1].first = F; pts[N+1].second = C;

        map<pair<ii,ii>, int> memo;

        cout << dp(0, 0, 0, 0, 0, memo) + 1 << "\n";
    }
}