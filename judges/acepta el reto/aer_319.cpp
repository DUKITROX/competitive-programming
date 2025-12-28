#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > adyList(10000);
int main(){
    //+1 *2 /3
    while(true){
        int start, fin;
        cin >> start;
        if(cin.fail()) break;
        cin >> fin;
        if(start==fin)cout << 0 << endl;
        else{

        queue<int> q;
        q.push(start);
        vector<bool> visited(10000, false);
        visited[start]=true;

        vector<int> dist(10000);
        bool encontrado=false;
        int actual = start;
        dist[start] = 0;
        while(!q.empty() && !encontrado){
            actual = q.front(); q.pop();
            if(adyList[actual].empty()){
                adyList[actual].push_back((actual+1)%10000);
                adyList[actual].push_back((actual*2)%10000);
                adyList[actual].push_back((actual/3)%10000);
            }
            for(int i : adyList[actual]){
                if(i == fin){
                    cout << dist[actual]+1<< endl;
                    encontrado=true;
                    break;
                }else if(!visited[i]){
                    visited[i]=true;
                    dist[i] = dist[actual]+1;
                    q.push(i);
                }
            }
        }
        }
        
    }
    return 0;
}