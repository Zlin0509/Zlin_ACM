//
// Created by 27682 on 2025/6/26.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10;


namespace Tree {
    int n = 1e5, fa[N * 2][20], dep[N * 2];
    vi e[N * 2];

    inline void add(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }

    inline void dfs(int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int v: e[u]) {
            if (v == f) continue;
            dfs(v, u);
        }
    }

    inline int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }

    inline int dis(int u, int v) {
        return (dep[u] + dep[v] - 2 * dep[lca(u, v)]) / 2;
    }
}

int n, m, q;
vi e[N];

int dfn[N], low[N], tot = 0;
int stk[N], top = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                int nx = ++Tree::n, vx;
                do {
                    vx = stk[top--];
                    Tree::add(nx, vx);
                } while (vx != v);
                Tree::add(nx, u);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}

inline void Zlin() {
    cin >> n >> m >> q;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tarjan(1);
    Tree::dfs(1, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << Tree::dis(x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
