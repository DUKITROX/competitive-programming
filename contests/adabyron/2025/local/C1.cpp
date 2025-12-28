#include <bits/stdc++.h>
using namespace std;

dijs

int main(){
    int n; while(cin >> n && n){
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        vector<vector<int>> m(n+1);

        while(q.size() > 1){
            int a = q.front(); q.pop(); 
            int b = q.front(); q.pop();
            int c;

            cout << "? " << a << " " << b << endl;
            cin >> c;

            m[c].push_back((c == a ? b : a));
            q.push(c);
        }
        int first = q.front(), second = m[first][0];
        for(int i = 1; i < m[first].size(); i++){
            cout << "? " << second << " " << m[first][i] << endl;
            cin >> second;
        }
        cout << "=> " << first << " " << second << endl;
    }
}

/*
5 2 4 3 1
4 2 3 1 5 7 6
*/