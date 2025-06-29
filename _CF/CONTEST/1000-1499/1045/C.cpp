//
// Created by 27682 on 2025/6/26.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10;

int n, m, q;

int cnt = 0, comp_count = 0;
vector<vi> e, tree;
vi dfn, low, fa, compID, siz;
vector<bool> vis;
set<pii> bridges;

inline void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    for (int v: e[u]) {
        if (!vis[v]) {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                bridges.insert({min(u, v), max(u, v)});
        } else if (v != fa[u]) low[u] = min(low[u], dfn[v]);
    }
}

inline void dfs(int u, int ID) {
    compID[u] = ID;
    for (int v: e[u])
        if (compID[v] == -1 && bridges.find({min(u, v), max(u, v)}) == bridges.end())
            dfs(v, ID);
}

inline void build(int n) {
    compID.assign(n + 1, -1);
    siz.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (compID[i] == -1) dfs(i, ++comp_count);
        ++siz[compID[i]];
    }
    for (auto it: bridges) {
        int u = compID[it.first], v = compID[it.second];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= comp_count; i++) siz[i] = siz[i] > 1;
}

vi dep, len;
int ffa[N][22];

inline void dfs1(int u, int fa) {
    dep[u] = dep[fa] + 1;
    len[u] += len[fa] + 1;
    ffa[u][0] = fa;
    for (int i = 1; i < 22; i++) ffa[u][i] = ffa[ffa[u][i - 1]][i - 1];
    for (int v: tree[u]) {
        if (v == fa) continue;
        dfs1(v, u);
    }
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; ~i; i--)
        if (dep[ffa[u][i]] >= dep[v])
            u = ffa[u][i];
    if (u == v) return u;
    for (int i = 20; ~i; i--)
        if (ffa[u][i] != ffa[v][i])
            u = ffa[u][i], v = ffa[v][i];
    return ffa[u][0];
}

inline void Zlin() {
    cin >> n >> m >> q;
    e.assign(n + 1, vi());
    tree.assign(n + 1, vi());
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cnt = comp_count = 0;
    vis.assign(n + 1, false);
    fa.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    bridges.clear();
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    build(n);
    dep.assign(comp_count + 1, 0);
    len.assign(comp_count + 1, 0);
    dfs1(1, 0);
    while (q--) {
        int a, b, ans = 0;
        cin >> a >> b;
        if (compID[a] == compID[b]) ans = 1;
        else {
            int ax = compID[a], bx = compID[b], s = lca(ax, bx);
            ans = len[ax] + len[bx] - len[s] - len[ffa[s][0]];
            if (siz[ax]) {
            }
            if (siz[bx]) {
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
