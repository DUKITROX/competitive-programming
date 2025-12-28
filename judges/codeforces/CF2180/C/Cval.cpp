// In the name of god
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[k], p = 0;
        if(k&1)
            for(int i = 0; i < k; i++)
                a[i] = n;
        else {
            for(int i = 30; i >= 0; i--) {
                if(n >> i & 1) {
                    for(int j = 0; j < k; j++)
                        if(j != min(p, k-1))
                            a[j] += (1 << i);
                    if(p < k)
                        p++;
                } else
                    for(int j = 0; j < p/2*2; j++)
                        a[j] += (1 << i);
            }
        }
		int SOL = 0;
        for(int i = 0; i < k; i++)
			SOL += a[i];
        for(int i = 0; i < k; i++)
			cout << a[i] << " ";
		cout << SOL << "\n";

		/*
		int SOL_MAL=0;
		for(int i = 0; i < k; i++){
			int a; cin >> a; SOL_MAL+=a;
		}
		if(SOL_MAL==SOL) cout << "OK\n";
		else{
			cout << "good solution total sum is " << SOL << "\n bad solution total sum is " << SOL_MAL << "\n";
		}
		*/
    }
    return 0;
}
