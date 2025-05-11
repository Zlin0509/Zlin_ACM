#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a[N][N], b[N][N];
vector<int> g[N << 1];
bool must[N << 1], vis[N], in[N];

bool dfs(int u) {
    if (in[u]) return false;
    in[u] = 1;
    for (int v: g[u]) {
        if (!vis[v] && !dfs(v)) return false;
    }
    in[u] = 0, vis[u] = 1;
    return true;
}

bool solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> b[i][j];
    }
    for (int t = 30; ~t; t--) {
        fill(must + 1, must + n + m + 1, 0);
        fill(vis + 1, vis + n + m + 1, 0);
        fill(in + 1, in + n + m + 1, 0);
        for (int i = 1; i <= n + m; i++) g[i].clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                bool A = (a[i][j] >> t) & 1, B = (b[i][j] >> t) & 1;
                if (B) g[i].push_back(j + n);
                else g[j + n].push_back(i);
                if (A && !B) must[i] = 1;
                if (!A && B) must[j + n] = 1;
            }
        }
        for (int i = 1; i <= n + m; i++) {
            if (must[i] && !dfs(i)) if (!dfs(i)) return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}
