//
// Created by Zlin on 2025/2/11.
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

ll dp[3010][2];

inline void Zlin()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<pll> w(n + 1);
    w[0] = {-1, -1};
    for (ll i = 1; i <= n; i++)
        cin >> w[i].first >> w[i].second;

    for (ll i = 1; i <= n; i++)
        dp[i][0] = dp[i][1] = 1e15;

    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = a * (i - 1);
        dp[i][1] = a * (i - 1) + b;
        for (ll j = 1; j < i; j++)
        {
            ll a1 = w[i].first, b1 = w[i].second;
            ll a2 = w[j].first, b2 = w[j].second;

            if (a1 >= a2 && b1 >= b2)
            {
                // 成立
                dp[i][0] = min(dp[i][0], dp[j][0] + a * (i - j - 1));
                dp[i][1] = min(dp[i][1], dp[j][1] + a * (i - j - 1) + b);
            }
            if (a1 >= b2 && b1 >= a2)
            {
                // 可以交换
                dp[i][1] = min(dp[i][1], dp[j][0] + a * (i - j - 1) + b);
                dp[i][0] = min(dp[i][0], dp[j][1] + a * (i - j - 1));
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
