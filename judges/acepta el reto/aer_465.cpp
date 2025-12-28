#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

int F,C;
int dx[4] = {-1,0,1,0}, dy[4] = {0, 1, 0, -1};
bool dentro(int x, int y){
    if(x >= 0 && x < C && y >= 0 && y < F) return true;
    else return false;
}
void solve(int F, int C){
    vector<string> arr(F); cin >> arr;
    ii pos;
    pos.first = 23;
    for(int i = 0; i < F; i++){
        for(int j = 0; j < C; j++) if(arr[i][j] == 'O'){
            pos.first = i;
            pos.second = j;
        } 
    }
    int izq=0,der=0,ant=-1,ANT=-1,END=0,KK=0;
    while(true){
        ant = -1;
        for(int i = 0; i < 4; i++){
            if(dentro(pos.first+dx[i], pos.second+dy[i]) && (arr[pos.first+dx[i]][pos.second+dy[i]] == '#' || arr[pos.first+dx[i]][pos.second+dy[i]] == 'O')){
                if(ANT == -1){
                    pos.first+=dx[i];
                    pos.second+=dy[i];
                    ant = i;
                    break; 
                }
                else if(ANT == 0 && i != 2){
                    pos.first+=dx[i];
                    pos.second+=dy[i];
                    ant = i;
                    break;
                }
                else if(ANT == 1 && i != 3){
                    pos.first+=dx[i];
                    pos.second+=dy[i];
                    ant = i;
                    break;
                }
                else if(ANT == 2 && i != 0){
                    pos.first+=dx[i];
                    pos.second+=dy[i];
                    ant = i;
                    break;   
                }
                else if(ANT == 3 && i != 1){
                    pos.first+=dx[i];
                    pos.second+=dy[i];
                    ant = i;
                    break;
                }
            }
        }
        if(ANT==0){
            if(ant==1)der++;
            else if(ant == 3)izq++;
        }else if(ANT == 1){
            if(ant == 2)der++;
            else if(ant == 0)izq++;
        }else if(ANT == 2){
            if(ant == 3)der++;
            else if(ant == 1)izq++;
        }else if(ANT == 3){
            if(ant == 0)der++;
            else if(ant == 2)izq++;
        }
        ANT = ant;
        if(arr[pos.first][pos.second] == 'O') break;
        /*
5 3
#O###
#...#
#####
        */
       KK++;
    }
    cout << izq << " " << der << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> C >> F) solve(F,C);
}