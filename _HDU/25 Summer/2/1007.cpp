//
// Created by 27682 on 2025/7/21.
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

constexpr int N = 5010;
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

int n, R, a[N];
ll dp[N][N], inv[N];

inline void Zlin() {
    cin >> n >> R;
    a[0] = R;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n - 1; i; i--) a[i] = max(a[i], a[i + 1]);
    dp[n][0] = 1;
    for (int i = n - 1; ~i; i--) {
        for (int j = 0; j <= n - i; j++) dp[i][j] = 0;
        ll b = 1;
        for (int j = 0; j < n - i; j++) {
            b = b * (a[i + 1] - j) % mo;
            b = b * inv[j + 1] % mo;
            dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mo;
            dp[i][j + 1] = (dp[i][j + 1] + dp[i + 1][j]) % mo;
            dp[i][0] = (dp[i][0] + (mo - b) * dp[i + 1][j]) % mo;
        }
    }
    ll ans = 0, b = 1;
    for (int k = 0; k <= n; k++) {
        ans = (ans + b * dp[0][k]) % mo;
        b = b * (R - k) % mo;
        b = b * inv[k + 1] % mo;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i < N; i++) inv[i] = qpow(i, mo - 2);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
