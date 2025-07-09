//
// Created by 27682 on 2025/7/6.
//
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 22;

typedef vector<int> vi;

int n, m, ans = 0, res = 1e9;

int dis[N][N], deg[N], vis[N];

vi have;

bool floyd() {
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 2; i <= n; i++) if (dis[1][i] == 1e9) return false;
    return true;
}

inline void dfs(int u, int val) {
    if (u == have.size()) {
        res = min(res, val);
        return;
    }
    if (vis[u]) return;
    vis[u] = true;
    for (int v = 0; v < have.size(); v++) {
        if (!vis[v]) {
            vis[v] = true;
            dfs(v + 1, val + dis[have[u]][have[v]]);
            vis[u] = false;
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 1e9;
        }
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        dis[u][v] = w, dis[v][u] = w;
        ++deg[u], ++deg[v];
        ans += w;
    }
    if (!floyd()) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) if (deg[i] & 1) have.push_back(i);
    dfs(0, 0);
    cout << ans + res << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
