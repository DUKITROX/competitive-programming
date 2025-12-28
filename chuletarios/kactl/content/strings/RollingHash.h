/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description:
 * Status: stress-tested
 */
// Rabin-Karp's algorithm specific code
typedef long long ll;

string T;
string P;
int n;
// Para el primer hash
const int p = 257;          // Base 1 (anteriormente 131)
const int M = 1e6+7;        // Módulo 1

// Para el segundo hash
const int p2 = 359;         // Base 2 (anteriormente 137)
const int M2 = 1e6+9;       // Módulo 2


int Pow[MAX_N];                                  // to store p^i % M
int h[MAX_N];                                    // to store prefix hashes

void computeRollingHash() {                      // Overall: O(n)
    Pow[0] = 1;                                    // compute p^i % M
    for (int i = 1; i < n; ++i)                    // O(n)
        Pow[i] = ((ll)Pow[i-1]*p) % M;
    h[0] = 0;
    for (int i = 0; i < n; ++i) {                  // O(n)
        if (i != 0) h[i] = h[i-1];                   // rolling hash
        h[i] = (h[i] + ((ll)T[i]*Pow[i]) % M) % M;
    }
}

int computeHash(string &s){
    int hash =0;
    int last = 0;
    for (int i = 0; i < s.size(); ++i) {                  // O(n)
        hash = (hash + ((ll)s[i]*Pow[i]) % M) % M;
    }
    return hash;
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) {                                    // repeats until b == 0
        int q = a/b;
        tie(a, b) = tuple(b, a%b);
        tie(x, xx) = tuple(xx, x-q*xx);
        tie(y, yy) = tuple(yy, y-q*yy);
    }
    return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return (x+m)%m;                                // this is the answer
}

int hash_fast(int L, int R) {                    // O(1) hash of any substr
  if (L == 0) return h[R];                       // h is the prefix hashes
  int ans = 0;
  ans = ((h[R] - h[L-1]) % M + M) % M;           // compute differences
  ans = ((ll)ans * modInverse(Pow[L], M)) % M;   // remove P[L]^-1 (mod M)
  return ans;
}

