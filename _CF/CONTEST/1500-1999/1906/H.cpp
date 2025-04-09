//
// Created by 27682 on 2025/4/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;
constexpr int N = 2e5;

ll fac[N + 10], inv[N + 10];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void dd() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[N] = qpow(fac[N], mo - 2);
    for (int i = N - 1; i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

inline ll comb(int n, int k) {
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vi cnta(26), cntb(26);
    for (char it: a) cnta[it - 'A']++;
    for (char it: b) cntb[it - 'A']++;
    vector dp(27, vll(m + 1));
    vector sum(26, vll(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < 26; i++) {
        sum[i][0] = dp[i][0];
        for (int j = 1; j <= cntb[i]; j++)
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mo;
        for (int j = 0; j <= cnta[i] && j <= cntb[i]; j++)
            dp[i + 1][cnta[i] - j] = comb(cnta[i], j) * sum[i][cntb[i] - j] % mo;
    }
    ll ans = dp[26][0] * fac[n] % mo;
    for (int it: cnta) ans = ans * inv[it] % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    dd();
    while (ttt--) Zlin();
    return 0;
}
