#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = double;
using ull = unsigned long long;
const int N = 5e5 + 5;
const int MAXN = 2e5 + 5;
const int M = 1e7 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ull base = 131;
ll f[20][20];
ll n, m, k, dp[64][20 * 20][20];

void solve() {
    cin >> n >> m >> k;
    dp[60][0][k] = 1;
    ll ans = 0;
    for (int i = 60; i >= 0; i--) {
        for (int j1 = 0; j1 < 20 * 20; j1++) {
            for (int j2 = 0; j2 <= k; j2++) {
                if (!dp[i][j1][j2]) continue;
                if (m >> i & 1) {
                    ll cnt = k;
                    for (int k1 = 0; k1 <= k; k1++) {
                        if (k1 * (k - k1) > j1) break;
                        for (int k2 = 0; k2 <= min(k1, j2); k2++) {
                            ll res = f[j2][k2] * f[k - j2][k1 - k2] % mod;
                            ll sum = (1ll << i) * (j1 - (k1 * (k - k1))) + n % (1ll << i);
                            if (i) {
                                sum /= (1ll << (i - 1));
                                if (sum < 400) dp[i - 1][sum][k2] = (dp[i - 1][sum][k2] + dp[i][j1][j2] * res) % mod;
                            } else {
                                if (sum == 0) ans = (ans + dp[i][j1][j2] * res) % mod;
                            }
                        }
                    }
                } else {
                    ll cnt = k - j2;
                    for (int k1 = 0; k1 <= cnt; k1++) {
                        if (k1 * (k - k1) > j1) break;
                        ll res = f[cnt][k1];
                        ll sum = (1ll << i) * (j1 - k1 * (k - k1)) + n % (1ll << i);
                        if (i) {
                            sum /= (1ll << (i - 1));
                            if (sum < 400) dp[i - 1][sum][j2] = (dp[i - 1][sum][j2] + dp[i][j1][j2] * res) % mod;
                        } else {
                            if (sum == 0) ans = (ans + dp[i][j1][j2] * res) % mod;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 20; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % mod;
        }
    }
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
