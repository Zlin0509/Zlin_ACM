//
// Created by Zlin on 2024/10/21.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
ll dp[N][2], a[N];
int n, c;
vi e[N];

inline void dfs(int u, int fa) {
    dp[u][0] = 0, dp[u][1] = a[u];
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += max(dp[v][0], dp[v][1] - c * 2);
    }
}

inline void Zlin() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << max({dp[1][0], dp[1][1]}) << '\n';
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}