//
// Created by 27682 on 2025/9/5.
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

ll c[20][20];
ll n, m, dp[64][18 * 19][19];
int k;

inline void Zlin() {
    cin >> n >> m >> k;
    dp[63][0][k] = 1;
    for (int i = 63; ~i; i--) {
        for (ll j1 = 0, j2; j1 < 18 * 19; j1++) {
            for (int k1 = 0; k1 <= k; k1++) {
                if (dp[i][j1][k1]) continue;
                j2 = (j1 + (n >> i & 1)) * 2;
                for (int c1 = 0; c1 <= k; c1++) {
                    ll jj = j2 - c1 * (k - c1);
                    if (jj >= 18 * 19 || jj < 0) continue;
                    if (m >> i & 1) {
                        for (int k2 = 0; k2 <= min(k1, c1); k2++) {
                            ll res = c[k1][k2] * dp[i][j1][k1] % mo;
                            dp[i - 1][jj][k2] = (dp[i - 1][jj][k2] + res) % mo;
                        }
                    } else {
                        if (k - k1 < k - c1) continue;
                        ll res = c[k - k1][k - c1] * dp[i][j1][k1] % mo;
                        dp[i - 1][jj][k1] = (dp[i - 1][jj][k1] + res) % mo;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) ans = (ans + dp[0][0][i]) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
