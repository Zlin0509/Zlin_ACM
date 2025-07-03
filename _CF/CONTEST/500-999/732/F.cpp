//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

constexpr int N = 4e5 + 10;


struct Tree {
    struct edge {
        int v, id;
    };

    vector<edge> e[N], g[N];
    int eid = -1;
    bool bridges[N];
    int dfn[N], low[N], tick;

    void adde(int u, int v) {
        ++eid;
        e[u].push_back({v, eid});
        e[v].push_back({u, eid});
    }

    void tarjan(int u, int pid) {
        dfn[u] = low[u] = ++tick;
        for (auto [v, id]: e[u]) {
            if (!dfn[v]) {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridges[id] = true;
            } else if (id != pid) low[u] = min(low[u], dfn[v]);
        }
    }

    int siz[N], compID[N], cnum;

    void dfs(int u, int cid) {
        ++siz[cid];
        compID[u] = cid;
        for (auto [v, eid]: e[u]) {
            if (compID[v] == -1 && !bridges[eid]) {
                dfs(v, cid);
            }
        }
    }

    vi tree[N];

    void build(int n) {
        fill(dfn + 1, dfn + 1 + n, 0);
        fill(low + 1, low + 1 + n, 0);
        tick = 0;
        for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, -1);
        fill(siz + 1, siz + 1 + n, 0);
        fill(compID + 1, compID + 1 + n, -1);
        cnum = 0;
        for (int i = 1; i <= n; i++) if (compID[i] == -1) dfs(i, ++cnum);
        for (int u = 1; u <= n; u++) {
            for (auto [v, id]: e[u]) {
                if (compID[u] != compID[v]) tree[compID[u]].push_back(compID[v]);
                else g[u].push_back({v, id});
            }
        }
    }

    bool vis_c[N];
    ll vis_g[N * 2];

    void dfs1(int u) {
        for (auto [v, id]: g[u]) {
            if (vis_g[id]) continue;
            vis_g[id] = 1ll * u * N + v;
            dfs1(v);
        }
    }

    void dcc_scc(int n) {
        for (int i = 1; i <= n; i++) if (!vis_c[compID[i]]) dfs1(i), vis_c[compID[i]] = true;
    }

    int fa[N];

    void dfs2(int u, int f) {
        fa[u] = f;
        for (int v: tree[u]) {
            if (v == f)continue;
            dfs2(v, u);
        }
    }

    int find_s() {
        int id = 0;
        for (int i = 1; i <= cnum; i++) if (siz[id] < siz[i]) id = i;
        dfs2(id, 0);
        return siz[id];
    }

    bool check(int u, int v, int tid) {
        if (fa[compID[u]] == compID[v]) return true;
        int ux = vis_g[tid] / N, vx = vis_g[tid] % N;
        if (ux == u && vx == v) return true;
        return false;
    }
} t;

int n, m, tid[N];
pii line[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        line[i] = {u, v};
        t.adde(u, v);
        tid[i] = t.eid;
    }
    t.build(n);
    t.dcc_scc(n);
    cout << t.find_s() << endl;
    for (int i = 1; i <= m; i++) {
        auto [u, v] = line[i];
        if (t.check(u, v, tid[i])) cout << u << ' ' << v << endl;
        else cout << v << ' ' << u << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
