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

constexpr int N = 1e5 + 10;

int n, m, q;

struct BCT {
    int n, tot, ts; // n 原图点数, tot 圆方树总点数
    vector<vi> g, tg; // g 原图, tg 圆方树
    vi dfn, low, st;
    vector<bool> cut;

    BCT(int _n = 0) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(n + 1, {});
        tg.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        cut.assign(n + 1, 0);
        st.clear();
        ts = 0;
        tot = n;
    }

    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++ts;
        st.push_back(u);
        int son = 0;
        for (int v: g[u]) {
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    son++;
                    if (fa != -1 || son > 1) cut[u] = true;
                    ++tot;
                    tg.resize(tot + 1);
                    while (true) {
                        int x = st.back();
                        st.pop_back();
                        tg[tot].push_back(x);
                        tg[x].push_back(tot);
                        if (x == v) break;
                    }
                    tg[tot].push_back(u);
                    tg[u].push_back(tot);
                }
            } else if (v != fa) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                st.clear();
                tarjan(i, -1);
            }
        }
    }
} bct;

struct LCA {
    int dep[N << 1], f[N << 1][22];

    LCA(int _n = 0) { init(_n); }

    void init(int _n) {
        for (int i = 1; i <= _n; i++) {
            dep[i] = 0;
            for (int j = 0; j < 22; j++) f[i][j] = 0;
        }
    }

    void dfs(int u, int fa, const vector<vi> &g) {
        f[u][0] = fa;
        for (int i = 1; i < 22; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        for (int v: g[u]) {
            if (v == fa) continue;
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
    lca.dfs(1, 0, bct.tg);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (lca.find(u, v) > n ? "Yes" : "No") << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
