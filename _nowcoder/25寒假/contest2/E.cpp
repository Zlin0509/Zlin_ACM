//
// Created by Zlin on 2025/1/23.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int inf = 0x3f3f3f3f;

int n, q;
ll f[200010][22];
ll a[200010], b[200010], c[200010];

inline void ST_prework()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = c[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline ll ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void Zlin()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i] + b[i - 1];
    for (int i = 1; i <= n; i++)
        c[i] = a[i] - b[i - 1];
    ST_prework();
    int l, r;
    while (q--)
    {
        cin >> l >> r;
        if (l == r)
            cout << 0 << endl;
        else
            cout << max(ST_query(l + 1, r) + b[l - 1], 0ll) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
