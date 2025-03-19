//
// Created by 27682 on 2025/3/19.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;

inline void Zlin()
{
    int n;
    cin >> n;
    vll a(n + 1), fac(n + 1), sum(n + 2), r(n + 1);
    vector dp(n + 2, vll(n + 1, 0));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][1] = fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * 2 % mo;
    for (int i = 1; i <= n; i++)
    {
        r[i] = min(i + 2, n + 1);
        while (r[i] <= n && a[r[i] - 1] < a[r[i]])
            ++r[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            sum[j] = 0;
        for (int j = i; j <= n; j++)
        {
            ll val = dp[i][j] * fac[j - i] % mo;
            sum[j] = (sum[j] + val) % mo;
            sum[r[j]] = (sum[r[j]] - val + mo) % mo;
        }
        for (int j = 1; j <= n; j++)
            sum[j] = (sum[j] + sum[j - 1]) % mo;
        for (int j = 1; j <= n; j++)
            dp[i + 1][j] = sum[j];
    }
    cout << dp[n + 1][n] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
