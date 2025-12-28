#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii>> vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        is >> v[i];
    return is;
}
void show(vi arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

struct sparseTable
{
    vector<vector<ll>> st;
    ll n, m;
    ll lg2(ll i)
    {
        return 31 - __builtin_clz(i);
    }
    sparseTable(const vector<ll> &v) : n(v.size()), m(lg2(v.size()))
    {
        st.assign(m + 1, vector<ll>(n));
        for (int j = 0; j < n; j++)
            st[0][j] = v[j];
        for (int i = 1; i <= m; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    ll query(ll L, ll R)
    {
        ll i = lg2(R - L + 1);
        return max(st[i][L], st[i][R + 1 - (1 << i)]);
    }
};

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (k == 0)
    {
        cout << "0\n";
        return;
    }
    vector<vector<ll>> arr(m, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[j][i];
    vector<sparseTable> STs;
    for (int i = 0; i < m; i++)
    {
        sparseTable ST(arr[i]);
        STs.push_back(ST);
    }
    ll i = 0, j = 0, I = -1, J = -1;
    while (j < n)
    {
        if (i > j)
            j++;
        ll cont = 0;
        for (int q = 0; q < m; q++)
            cont += STs[q].query(i, j);

        if (cont <= k)
        {
            if (j - i >= J - I)
            {
                I = i;
                J = j;
            }
            j++;
        }
        else
            i++;
    }
    if (I == -1)
        for (int i = 0; i < m; i++)
            cout << "0 ";
    else
        for (int i = 0; i < m; i++)
            cout << STs[i].query(I, J) << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
/*
1 1 0
1
*/
