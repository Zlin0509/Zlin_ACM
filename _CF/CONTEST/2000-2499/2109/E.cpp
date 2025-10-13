//
// Created by 27682 on 2025/10/13.
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

constexpr ll mo = 998244353;
constexpr int N = 502;

ll dp[N][N];

ll fac[N], inv[N];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mo;
    inv[N - 1] = qpow(fac[N - 1], mo - 2);
    for (int i = N - 2; i; i--) inv[i] = inv[i + 1] * (i + 1) % mo;
}

inline ll C(int n, int k) {
    if (n < k) return 0;
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n + 1; i++) for (int j = 0; j <= k; j++) dp[i][j] = 0;
    dp[n + 1][0] = 1;
    for (int i = n + 1; i > 1; i--) {
        int op = s[i - 1] - '0';
        for (int j = 0; j <= k; j++) {
            for (int q = 0; q + j <= k; q++) {
                if (op) dp[i - 1][j + q] = (dp[i - 1][j + q] + dp[i][j] * C((j + q) / 2, q) % mo) % mo;
                else dp[i - 1][j + q] = (dp[i - 1][j + q] + dp[i][j] * C((j + q + 1) / 2, q) % mo) % mo;
            }
        }
    }
    cout << dp[1][k] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    init();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
