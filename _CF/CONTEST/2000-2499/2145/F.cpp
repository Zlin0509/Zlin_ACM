//
// Created by 27682 on 2025/11/5.
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

constexpr int N = 2520;

int n, a[10], b[10];
ll m, dp[10][N][50];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            if ((j + 1) % a[i] != b[i]) dp[i][j][0] = 1;
            else dp[i][j][0] = 0;
        }
    }
    for (int k = 1; k < 50; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j][k] = dp[i][j][k - 1] + dp[((1ll << (k - 1)) + i) % n][(dp[i][j][k - 1] + j) % N][k - 1];
            }
        }
    }
    if (dp[0][0][49] < m) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0, now = 0;
    for (int i = 49; ~i; i--) {
        if (now + dp[ans % n][now % N][i] < m) {
            now += dp[ans % n][now % N][i];
            ans += 1ll << i;
            // cout << ans << ' ' << now << endl;
        }
    }
    cout << ans + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
