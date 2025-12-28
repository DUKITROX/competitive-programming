#include <bits/stdc++.h>
using namespace std;

#define int long long


struct  UFDS{
    vector<int> p;
    int num_comps;
    UFDS(int n) : num_comps(n), p(n, -1){}
    int find(int x){
        if(p[x] < 0) return x;
        else return p[x] = find(p[x]);
    }
    void join(int x, int y){
        int i = find(x);
        int j = find(y);
        if(i == j){
            stk.push({-1,-1});
            return;
        }
        
        if(p[i] < p[j])
            swap(i, j);
        p[j] += p[i];
        p[i] = j;
        num_comps--;
    }
    int size(int x){
        return -p[find(x)];
    }
};

int32_t main(){
    
}