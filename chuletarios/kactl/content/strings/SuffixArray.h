/**
 * Author: 罗穗骞, chilli
 * Date: 2019-04-11
 * License: Unknown
 * Source: Suffix array - a powerful tool for dealing with strings
 * (Chinese IOI National team training paper, 2009)
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is $i$'th in the sorted suffix array.
 * The returned vector is of size $n+1$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * The input string must not contain any nul chars.
 * Time: O(n \log n)
 * Status: stress-tested
 */
#pragma once
using vi=vector<int>;
using vvi = vector<vi>;
using ii= pair<int, int>;

typedef vector<int> vi;
typedef pair<int, int> ii;

class SuffixArray {
private:
    vi RA;                                         // Rank array
    vector<vi> st;                                 // Sparse table for LCP
    vi logTable;                                   // Precomputed log values

    void countingSort(int k) {                     // O(n)
        int maxi = max(300, n);                    // Up to 255 ASCII chars
        vi c(maxi, 0);                             // Frequency table
        for (int i = 0; i < n; ++i)                // Count frequencies
            ++c[i + k < n ? RA[i + k] : 0];
        for (int i = 0, sum = 0; i < maxi; ++i) {  // Prefix sums
            int t = c[i]; c[i] = sum; sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i)                // Sort SA
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA);                          // Update SA
    }

    void constructSA() {                           // O(n log n)
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0);             // Initial SA
        RA.resize(n);
        for (int i = 0; i < n; ++i) RA[i] = T[i];  // Initial ranks
        for (int k = 1; k < n; k <<= 1) {          // Radix sort log n times
            countingSort(k);                       // Sort by 2nd key
            countingSort(0);                       // Sort by 1st key
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;                     // Re-ranking
            for (int i = 1; i < n; ++i)
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
            swap(RA, tempRA);                      // Update RA
            if (RA[SA[n-1]] == n-1) break;         // Optimization
        }
    }

    void computeLCP() {                            // Kasai's algorithm O(n)
        vi Phi(n), PLCP(n);
        Phi[SA[0]] = -1;
        for (int i = 1; i < n; ++i)
            Phi[SA[i]] = SA[i-1];
        for (int i = 0, L = 0; i < n; ++i) {
            if (Phi[i] == -1) { PLCP[i] = 0; continue; }
            while (i + L < n && Phi[i] + L < n && T[i + L] == T[Phi[i] + L]) 
                L++;
            PLCP[i] = L;
            L = max(L - 1, 0);
        }
        LCP.resize(n);
        for (int i = 0; i < n; ++i)
            LCP[i] = PLCP[SA[i]];
    }

    void buildSparseTable() {                      // Build RMQ sparse table
        logTable.resize(n + 1);
        logTable[0] = 0; logTable[1] = 0;
        for (int i = 2; i <= n; ++i)
            logTable[i] = logTable[i >> 1] + 1;
        int k = logTable[n] + 1;
        st.resize(k, vi(n));
        for (int i = 0; i < n; ++i)
            st[0][i] = LCP[i];
        for (int j = 1; j < k; ++j)
            for (int i = 0; i + (1 << j) <= n; ++i)
                st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
    }

public:
    const char* T;                                 // Input string
    const int n;                                   // Length of T
    vi SA;                                         // Suffix Array
    vi LCP;                                        // LCP array

    SuffixArray(const char* initialT, const int _n) : T(initialT), n(_n) {
        constructSA();
        computeLCP();
        buildSparseTable();
    }

    ii stringMatching(const char *P) {             // O(m log n)
        int m = strlen(P);
        int lo = 0, hi = n - 1;
        while (lo < hi) {                         // Lower bound
            int mid = (lo + hi) / 2;
            int res = strncmp(T + SA[mid], P, m);
            (res >= 0) ? hi = mid : lo = mid + 1;
        }
        if (strncmp(T + SA[lo], P, m) != 0) return {-1, -1};
        ii ans; ans.first = lo;
        hi = n - 1;                              // Upper bound
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int res = strncmp(T + SA[mid], P, m);
            (res > 0) ? hi = mid : lo = mid + 1;
        }
        if (strncmp(T + SA[hi], P, m) != 0) --hi;
        ans.second = hi;
        return ans;
    }

    int getLCP(int i, int j) {                    // LCP of suffixes starting at i and j
        if (i == j) return n - i;
        int l = RA[i], r = RA[j];
        if (l > r) swap(l, r);
        if (l == r) return n - SA[l];
        int a = l + 1, b = r;
        int len = b - a + 1;
        int k = logTable[len];
        return min(st[k][a], st[k][b - (1 << k) + 1]);
    }
};
int main(){
    string cad;
    cin>> cad;
    cad.push_back('#');
    SuffixArray sa(cad.c_str(), cad.size());
    int n; cin >> n;
    int ini, fin;
    for (int i = 0; i < n; i++)
    {
        cin >> ini>> fin;
        cout << sa.getLCP(ini, fin) << "\n";
    }
    
    return 0;
}