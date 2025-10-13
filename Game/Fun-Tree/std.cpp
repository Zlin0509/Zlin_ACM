//
// Created by Zlin on 2025/9/23.
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

constexpr int N = 4e5 + 10;

vi e[N], E[N];

int dfn[N], low[N], tot = 0;
int cnt = 0;
int vis[N], fa[N], compID[N], siz[N];

set<pii> bridges;

inline void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++tot;
    for (int v: E[u]) {
        if (!vis[v]) {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) bridges.insert({min(u, v), max(u, v)});
        } else if (v != fa[u]) low[u] = min(low[u], dfn[v]);
    }
}

inline void dfs(int u, int ID) {
    compID[u] = ID;
    for (int v: E[u])
        if (compID[v] == -1 && bridges.find({min(u, v), max(u, v)}) == bridges.end())
            dfs(v, ID);
}

inline void build(int n) {
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    fill(compID + 1, compID + n + 1, -1);
    for (int i = 1; i <= n; i++)
        if (compID[i] == -1)
            dfs(i, ++cnt);
    for (auto it: bridges) {
        int u = compID[it.first], v = compID[it.second];
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) siz[compID[i]]++;
}

int n, m, q, val[N];
int ffa[N][22], dep[N];

inline void dfs1(int u, int f) {
    ffa[u][0] = f;
    for (int i = 1; i < 22; i++) ffa[u][i] = ffa[ffa[u][i - 1]][i - 1];
    dep[u] = dep[f] + 1;
    val[u] = (siz[u] > 1) + val[f];
    for (int v: e[u]) {
        if (v == f) continue;
        dfs1(v, u);
    }
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 21; ~i; i--) if (dep[ffa[u][i]] >= dep[v]) u = ffa[u][i];
    if (u == v) return u;
    for (int i = 21; ~i; i--) if (ffa[u][i] != ffa[v][i]) u = ffa[u][i], v = ffa[v][i];
    return ffa[u][0];
}

int fx[N];

inline int find(int u) { return fx[u] == u ? u : fx[u] = find(fx[u]); }

inline void merge(int x, int y) {
    int fxx = find(x), fyy = find(y);
    if (fxx == fyy) return;
    fx[fxx] = fyy;
}

inline void Zlin() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) fx[i] = i;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        E[x].emplace_back(y);
        E[y].emplace_back(x);
        merge(x, y);
    }
    build(n);
    fill(vis + 1, vis + 1 + n, 0);
    for (int i = 1; i <= cnt; i++) if (!vis[i]) dfs1(i, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (find(x) != find(y)) {
            cout << "NO" << endl;
        } else {
            x = compID[x], y = compID[y];
            int s = lca(x, y);
            int ans = val[x] + val[y] - val[s] - val[ffa[s][0]];
            cout << (ans ? "YES" : "NO") << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    clock_t start = clock(); // 开始计时
    while (ttt--) Zlin();
    clock_t end = clock(); // 结束计时
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "运行时间: " << time_taken << " 秒" << endl;
    return 0;
}
