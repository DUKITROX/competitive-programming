#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cmp{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		return p1.first < p2.first || p1.first == p2.first && p1.second > p2.second;
	}
};

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n,k; while(cin >> n >> k && (n||k)){
		vector<int> arr(n);
		vector<long long> kth(n-k+1);
		vector<bool> v1(n-k+1,false);
		priority_queue<pair<long long, long long >, vector<pair<int,int>>, cmp> pq;

		long long sum = 0, SIU = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i]; sum += arr[i];
			SIU += arr[i];
			if(i-k >= 0) sum -= arr[i-k];
			if(i-k+1 >= 0){
				kth[i-k+1] = sum; 
				pq.push({sum,i-k+1});
			}
		}

		long long chav = 0;
		while(!pq.empty()){
			long long c = pq.top().first, p = pq.top().second; pq.pop();

			if(!v1[p]){
				v1[p] = true;

				bool l=false, r=false;

				for(long long i = 1; i < k && (!l || !r); i++){
					v1[min(n-k, p+i)] = true;
					v1[max(0LL, p-i)]  = true;
				}
				chav += c;
			}
		}

		vector<long long> dp(n,0LL);
		dp[k-1] = kth[0];
		long long M = kth[0];

		for(int i = k; i < n; i++){
			dp[i] = max(dp[i-k] + kth[i-k+1], M);
			M = max(M, dp[i]);
		}
		cout << SIU - chav << "\n";
	}
}
