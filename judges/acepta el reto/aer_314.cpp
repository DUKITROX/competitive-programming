#include <iostream>
using namespace std;

int A[10000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin >> casos;
    while(casos--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> A[i];
        int min = 0, max = 0;
        for(int i = 1; i < n-1; i++){
            if(A[i-1] < A[i] && A[i] > A[i+1]) max++;
            if(A[i-1] > A[i] && A[i] < A[i+1]) min++;
        }
        cout << max << " " << min << "\n";
    }
    return 0;
}