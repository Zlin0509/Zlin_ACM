//
// Created by 27682 on 2025/9/5.
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

constexpr int N = 1e3 + 10;

/*

1
5 4 2
1 2
2 3
3 1
4 5
4 5
1 2

1
5 5 2
1 2
2 3
3 1
3 4
4 5
4 5
1 3

1
5 6 2
1 2
2 3
3 1
3 4
4 5
5 1
4 5
1 3

 */

int n, m, q;

struct BCT {
    int n, tot, ts;
    vi g[N]; // 原图邻接表
    vi tg[N * 2]; // 圆方树邻接表
    int dfn[N], low[N];
    int st[N], st_sz;
    bool cut[N];

    BCT() { init(0); }

    void init(int _n) {
        n = _n;
        tot = n;
        ts = 0;
        st_sz = 0;
        memset(dfn, 0, sizeof(int) * (n + 1));
        memset(low, 0, sizeof(int) * (n + 1));
        memset(cut, 0, sizeof(int) * (n + 1));
        for (int i = 0; i <= n; i++) g[i].clear();
        for (int i = 0; i <= n * n + 1; i++) tg[i].clear();
    }

    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++ts;
        st[st_sz++] = u;
        int son = 0;
        for (int v: g[u]) {
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    son++;
                    if (fa != -1 || son > 1) cut[u] = true;
                    vi bcc;
                    while (true) {
                        int x = st[--st_sz];
                        bcc.push_back(x);
                        if (x == v) break;
                    }
                    bcc.push_back(u);
                    if (bcc.size() > 2) {
                        ++tot;
                        tg[tot].clear();
                        for (int x: bcc) {
                            tg[tot].push_back(x);
                            tg[x].push_back(tot);
                        }
                    }
                }
            } else if (v != fa) low[u] = min(low[u], dfn[v]);
        }
    }

    void build() {
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) {
                st_sz = 0;
                tarjan(i, -1);
            }
    }
} bct;

struct LCA {
    int dep[N * 2], f[N * 2][22];

    void init(int n) {
        memset(dep, 0, sizeof(int) * (n + 1));
        for (int i = 0; i <= n; i++) memset(f[i], 0, sizeof(f[i]));
    }

    void dfs(int u, int fa, vi g[]) {
        f[u][0] = fa;
        for (int i = 1; i < 22; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        for (int v: g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u, g);
        }
    }

    int find(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 21; ~i; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
        if (u == v) return u;
        for (int i = 21; ~i; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
        return f[u][0];
    }
} lca;

inline void Zlin() {
    cin >> n >> m >> q;
    bct.init(n);
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        bct.add(u, v);
    }
    bct.build();
    lca.init(bct.tot);
    for (int i = n + 1; i <= bct.tot; i++) if (!lca.dep[i]) lca.dfs(i, 0, bct.tg);
    for (int i = 1; i <= n; i++) if (!lca.dep[i]) lca.dfs(i, 0, bct.tg);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (lca.find(u, v) > n ? "Yes" : "No") << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
