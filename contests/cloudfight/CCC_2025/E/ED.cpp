#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, T;
        char comma;
        cin >> x >> comma >> y >> T;
        int w, z;
        cin >> w >> comma >> z;
        
        vector<int> x_list;
        if (x > 0) {
            x_list.push_back(0);
            for (int j = 0; j < x; j++) {
                x_list.push_back(1);
            }
            x_list.push_back(0);
        } else if (x < 0) {
            x_list.push_back(0);
            for (int j = 0; j < -x; j++) {
                x_list.push_back(-1);
            }
            x_list.push_back(0);
        } else {
            x_list.push_back(0);
        }
        
        vector<int> sx;
        sx.push_back(0);
        for (int j = 0; j < x_list.size(); j++) {
            sx.push_back(sx.back() + x_list[j]);
        }
        
        int T_start = -1, T_end = -1;
        for (int j = 1; j < sx.size(); j++) {
            if (sx[j] >= w - 2.5 && sx[j] <= w + 2.5) {
                if (T_start == -1) T_start = j - 1;
                T_end = j - 1;
            }
        }
        
        int V = y;
        if (T_start != -1) {
            if (y >= z - 2.5 && y <= z + 2.5) {
                if (y >= z) V = z + 3;
                else V = z - 3;
            }
        }
        
        int L1 = (V == 0) ? 1 : abs(V) + 2;
        if (T_start != -1 && T_start < L1) {
            int new_zeros = L1 - T_start;
            vector<int> new_x_list(new_zeros, 0);
            new_x_list.insert(new_x_list.end(), x_list.begin(), x_list.end());
            x_list = new_x_list;
            sx.clear();
            sx.push_back(0);
            for (int j = 0; j < x_list.size(); j++) {
                sx.push_back(sx.back() + x_list[j]);
            }
            T_start = -1;
            T_end = -1;
            for (int j = 1; j < sx.size(); j++) {
                if (sx[j] >= w - 2.5 && sx[j] <= w + 2.5) {
                    if (T_start == -1) T_start = j - 1;
                    T_end = j - 1;
                }
            }
        }
        
        vector<int> y_list;
        vector<int> segment1;
        if (V > 0) {
            segment1.push_back(0);
            for (int j = 0; j < V; j++) {
                segment1.push_back(1);
            }
            segment1.push_back(0);
        } else if (V < 0) {
            segment1.push_back(0);
            for (int j = 0; j < -V; j++) {
                segment1.push_back(-1);
            }
            segment1.push_back(0);
        } else {
            segment1.push_back(0);
        }
        
        vector<int> segment2;
        if (T_start != -1) {
            int L2 = T_end - T_start + 1;
            segment2.resize(L2, 0);
        }
        
        vector<int> segment3;
        int diff = y - V;
        if (diff > 0) {
            segment3.push_back(0);
            for (int j = 0; j < diff; j++) {
                segment3.push_back(1);
            }
            segment3.push_back(0);
        } else if (diff < 0) {
            segment3.push_back(0);
            for (int j = 0; j < -diff; j++) {
                segment3.push_back(-1);
            }
            segment3.push_back(0);
        } else {
            segment3.push_back(0);
        }
        
        int pre_zeros = 0;
        if (T_start != -1) {
            pre_zeros = T_start - segment1.size() + 1;
            if (pre_zeros < 0) pre_zeros = 0;
        }
        y_list.resize(pre_zeros, 0);
        y_list.insert(y_list.end(), segment1.begin(), segment1.end());
        if (T_start != -1) {
            y_list.insert(y_list.end(), segment2.begin(), segment2.end());
        }
        y_list.insert(y_list.end(), segment3.begin(), segment3.end());
        
        for (int j = 0; j < x_list.size(); j++) {
            if (j > 0) cout << " ";
            cout << x_list[j];
        }
        cout << endl;
        for (int j = 0; j < y_list.size(); j++) {
            if (j > 0) cout << " ";
            cout << y_list[j];
        }
        cout << endl;
    }
    return 0;
}
