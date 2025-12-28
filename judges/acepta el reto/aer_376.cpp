#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        int num_picos = 0, nums[1000], num_anterior;

        for(int i = 0; i < n; i++){
            cin >> nums[i];
            if(i == n - 1){
                if(nums[i] > num_anterior && nums[i] > nums[0]) num_picos++;
                if(nums[0] > nums[1] && nums[0] > nums[i]) num_picos++;
            }
            if(i > 1)
                if(num_anterior > nums[i] && num_anterior > nums[i-2]) num_picos++;
            num_anterior = nums[i];
        }
        cout << num_picos << endl;
    }
    return 0;
}