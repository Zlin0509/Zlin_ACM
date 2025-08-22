//
// Created by Zlin on 2025/8/19.
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

constexpr int N = 3010;

int n, dep[N], s[N], f[N][22];
pii idx[N];
vi e[N];

inline void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < 22; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 21; ~i; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    if (u == v) return u;
    for (int i = 21; ~i; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return f[u][0];
}

inline int cal(int pos, int x) {
    int len = idx[n].first - dep[s[pos]] + x;
    return max(len, idx[pos - 1].first - 1);
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) idx[i] = {dep[i], i};
    sort(idx + 1, idx + n + 1);
    s[n] = idx[n].second;
    for (int i = n - 1; i; i--) s[i] = lca(s[i + 1], idx[i].second);
    for (int x = 1; x <= n; x++) {
        int ans = idx[n].first - 1;
        for (int i = 2; i <= n; i++) ans = min(ans, cal(i, x));
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
