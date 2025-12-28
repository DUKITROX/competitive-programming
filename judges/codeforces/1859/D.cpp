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

bool cmp(ii a, ii b){
    if(a.first < b.first){
        return true;
    }
    if(a.first == b.first){
        if(a.second >= b.second) return true;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    vii intr(n),arr;
    int low,high,aux;
    for(int i = 0; i < n; i++){
        cin >> low >> aux >> aux >> high;
        intr[i] = make_pair(low, high);
    }
    sort(intr.begin(), intr.end());
    ii p = intr[0];
    low = p.first; high = p.second;
    for(int i = 1; i < n; i++){
        if(intr[i].first <= high){
            high = max(high,intr[i].second);
        }else{
            arr.push_back(make_pair(low,high));
            low = intr[i].first;
            high = intr[i].second;
        }
    }
    arr.push_back(make_pair(low,high));
    cin >> n; vii nums(n); vi sol(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
    int ind = 0;
    for(int i = 0; i < n; i++){
        while(ind < arr.size() - 1 && arr[ind].second < nums[i].first){
            ind++;
        }
        if(nums[i].first < arr[ind].first){
            sol[nums[i].second] = nums[i].first;
            sol[nums[i].first] = nums[i].second;
        }else if(arr[ind].first <= nums[i].first && nums[i].first <= arr[ind].second){
            sol[nums[i].second] = arr[ind].second;
        }else{
            sol[nums[i].second] = nums[i].first;
        }
    }
    show(sol);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}