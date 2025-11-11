//
// Created by 27682 on 2025/11/11.
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

constexpr ll mo = 1e9 + 7;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

int n, m, k, c[22], dp[22][1 << 21][2], cnt[22];
ll val[1000005];

inline void Zlin() {
    cin >> n >> m >> k;
    fill(c + 1, c + n + 1, 0);
    fill(cnt + 0, cnt + n + 1, 0);
    for (int i = 1; i <= m; i++) val[i] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j < 1 << i; j++) dp[i][j][0] = 1, dp[i][j][1] = 0;
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        c[x] = 1;
    }
    dp[1][1][0] = dp[1][1][1] = 0;
    dp[1][0][0] = dp[1][0][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 1 << i; j++) {
            for (int q = 0, tmp; q < i; q++) {
                if (c[q + 1]) {
                    tmp = j % (1 << q) + ((j >> (1 + q)) << q);
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][tmp][0]);
                    dp[i][j][0] = min(dp[i][j][0], dp[i - 1][tmp][1]);
                }
            }
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        if (dp[n][i][0]) {
            int cx = 0;
            for (int j = 0; j < n; j++) cx += i >> j & 1;
            cnt[cx]++;
        }
    }
    for (int t = 1; t <= m; t++) {
        for (int cx = 0; cx <= n; cx++) {
            val[t] = (val[t] + qpow(m - t, cx) * qpow(t, n - cx) % mo * cnt[cx] % mo) % mo;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + i * (val[i] - val[i - 1] + mo) % mo) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
