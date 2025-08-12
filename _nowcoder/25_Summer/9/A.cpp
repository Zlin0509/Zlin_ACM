//
// Created by Zlin on 2025/8/12.
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

constexpr int N = 2e5 + 10;

struct Node {
    int ls, rs;
} a[N];

int n;
int dp[N][40];

inline void dfs(int u) {
    if (!u) return;
    for (int j = 0; j < 40; j++) dp[u][j] = 2e5;
    int lx = a[u].ls, rx = a[u].rs;
    dfs(lx), dfs(rx);
    dp[u][0] = dp[lx][0] + dp[rx][0] + 1;
    dp[u][1] = dp[lx][0] + dp[rx][0];
    for (int j = 2; j < 40; j++) {
        dp[u][j] = min(dp[u][j], dp[lx][j - 1] + dp[rx][j - 1]);
        dp[u][j] = min(dp[u][j], dp[lx][j - 2] + dp[rx][j - 1]);
        dp[u][j] = min(dp[u][j], dp[lx][j - 1] + dp[rx][j - 2]);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].ls >> a[i].rs;
    dfs(1);
    int ans = n;
    for (int i = 0; i < 40; i++) ans = min(ans, dp[1][i]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int j = 2; j < 40; j++) dp[0][j] = dp[0][j - 1] + dp[0][j - 2] + 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
