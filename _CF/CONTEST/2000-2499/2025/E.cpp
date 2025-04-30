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

constexpr ll N = 1010, mo = 998244353;
ll f[N][N], g[N][N], n, m;

inline void Zlin() {
    cin >> n >> m;
    f[0][0] = 1;
    ll i, j, k;
    for (i = 1; i <= m; i++) {
        f[i][0] = f[i - 1][1];
        for (j = 1; j <= m; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j + 1]) % mo;
        }
    }
    g[1][0] = 1;
    for (i = 2; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            for (k = j; k <= m; k++) {
                g[i][k] = (g[i][k] + g[i - 1][k - j] * f[m][j]) % mo;
            }
        }
    }
    ll ans = 0;
    for (i = 0; i <= m; i++) ans = (ans + g[n][i] * f[m][i]) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
