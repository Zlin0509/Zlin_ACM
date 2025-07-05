//
// Created by 27682 on 2025/7/6.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
ll dp[5010][5010];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            dp[i][j] = 0;
        }
    }
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = n - i + 1; j >= 1; j--)
            dp[i][j] = (dp[i + 1][j] + i * (n - i + 1 - (j - 1)) % m * dp[i + 1][j - 1]) % m;
        dp[i][0] = 1;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[1][i]) % m;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
