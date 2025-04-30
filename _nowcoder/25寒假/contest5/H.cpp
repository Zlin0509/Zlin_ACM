//
// Created by Zlin on 2025/2/8.
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

constexpr int MOD = 998244353;

constexpr int N = 3010;

vi a;
ll f1[N][22], f2[N][22];
int n, k;

inline void ST_prework()
{
    for (int i = 1; i <= n; i++)
        f1[i][0] = f2[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
            f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
        }
}

inline ll ST_query(int l, int r)
{
    if (l > r)
        swap(l, r);
    int k = log(r - l + 1) / log(2);
    return max(f1[l][k], f1[r - (1 << k) + 1][k]) * min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

ll sum[N][N];
ll dp[N][N];

inline void Zlin()
{
    cin >> n >> k;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ST_prework();

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            sum[i][j] = ST_query(i, j);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            ll cnt = 0;
            for (int q = i; q >= j; q--)
            {
                cnt += sum[q][i];
                dp[i][j] += dp[q - 1][j - 1] + cnt;
            }
        }
    }
    cout << dp[n][k] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
