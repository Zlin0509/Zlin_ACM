//
// Created by Zlin on 2025/4/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
constexpr ll mo = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline ll find_cnt(int n, int m) {
    vll dp(m, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {
        vll dp1(m, 0);
        for (ll j = 0; j < m; j++) {
            dp1[j] = (dp1[j] + dp[j]) % mo;
            dp1[(j + i) % m] = (dp1[(j + i) % m] + dp[j]) % mo;
        }
        dp = dp1;
    }
    return dp[0];
}

inline void Zlin() {
    ll n, m;
    cin >> n >> m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
