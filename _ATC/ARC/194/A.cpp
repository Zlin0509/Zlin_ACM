//
// Created by 27682 on 2025/3/10.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll inf = 1e16;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector dp(n + 1, vll(2, 0));
    dp[1][1] = a[1],dp[1][0] = -inf;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
