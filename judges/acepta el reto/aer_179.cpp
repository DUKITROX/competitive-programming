#include <iostream>
#include <vector>
using namespace std;

#define LSOne(S) ((S) & -(S))

struct FenwickTree{
   vector<int> ft;
   FenwickTree(int m){
      ft.assign(m+1, 0);
   }
   int rsq(int j){
      int sum = 0;
      for(; j; j -= LSOne(j))
         sum += ft[ j ];
      return sum;
   }
   int rsq(int i, int j){
      return rsq( j ) - rsq( i - 1 );
   }
   void update(int i, int v){
      for(; i < (int)ft.size(); i += LSOne(i))
         ft[ i ] += v;
   }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n, q;
        cin >> n;
        if(n == 0) break;
        int aux;
        FenwickTree ft(n);
        for(int i = 1; i <= n; i++) {
            cin >> aux;
            ft.update(i, aux);
        }
        int a,b;
        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> a >> b;
            if(a == 1)
                cout << ft.rsq(a,b) << "\n";
            else
                cout << ft.rsq(a,b) << "\n";
        }
    }
    return 0;
}