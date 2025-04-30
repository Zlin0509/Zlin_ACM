#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8;

int n, f;
long long a[2010]{};
long long dp[2010][1010]{};

int main()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= f;
    for (int i = 1; i <= n; i++)
        dp[i][a[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < f; j++)
        {
            dp[i][j] = dp[i - 1][j] % mod + dp[i - 1][(j - a[i] + f) % f] % mod + dp[i][j] % mod;
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][0];
}