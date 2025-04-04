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

constexpr ll mo = 1e9 + 7;


inline void Zlin() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector dp(m + 1, vll(v + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        vector ndp = dp;
        for (int j = 0; j < m; j++) {
            for (int q = 0; q <= v - g[i]; q++) {
                if (ndp[j][q] != 0) {
                    ndp[j + 1][q + g[i]] = (ndp[j + 1][q + g[i]] + ndp[j][q]) % mo;
                }
            }
        }
        dp = ndp;
    }

    ll ans = 0;
    for (int i = 0; i <= v; i++) {
        ans = (ans + dp[m][i]) % mo;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
