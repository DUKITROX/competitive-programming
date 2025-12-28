#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int num;
        cin >> num;
        if(num == 0) break;

        vector<int> nums;
        int aux;
        for(int i = 0; i < num; i++){
            cin >> aux;
            nums.push_back(aux);
        }
        sort(nums.begin(), nums.end());
        if(num%2){
            cout << 2*nums[num/2] << endl;
        }else{
            int n1 = nums[num/2-1], n2 = nums[num/2];
            n1 = (n1+n2);
            cout << n1 << endl;
        }
    }
    return 0;
}