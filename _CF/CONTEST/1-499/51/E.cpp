//
// Created by 27682 on 2025/7/10.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int N = 701;

int n, m;
int dp[N][N][4], deg[N];
ll ans = 0;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        ++dp[u][v][1], ++dp[v][u][1];
        ++deg[u], ++deg[v];
    }
    for (int len = 2; len <= 3; len++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    dp[i][j][len] += dp[i][k][1] * dp[k][j][len - 1];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += dp[i][j][2] * dp[i][j][3];
        }
    }
    ans /= 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < j; k++) {
                if (dp[i][j][1] && dp[j][k][1] && dp[k][i][1]) {
                    ans -= deg[i] + deg[j] + deg[k] - 3;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
