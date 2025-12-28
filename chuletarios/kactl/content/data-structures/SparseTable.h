/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed.
 * Time:
 * Status: stress-tested
 */
struct sparseTable{
    vector<vector<int>> st;
    int n,m;
    int lg2(int i){
        return 31 - __builtin_clz(i);
    }
    sparseTable(const vector<int>& v) : n(v.size()), m(lg2(v.size())){
        st.assign(m+1, vector<int>(n));
        for(int j = 0; j < n; j++) st[0][j] = v[j];
        for(int i = 1; i <= m; i++)
            for(int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    }
    int query(int L, int R){
        int i =  lg2(R-L+1);
        return min(st[i][L], st[i][R + 1 - (1 << i)]);
    }
 };