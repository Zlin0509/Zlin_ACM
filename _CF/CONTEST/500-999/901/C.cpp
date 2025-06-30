//
// Created by 27682 on 2025/6/30.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

constexpr int N = 3e5 + 90;
constexpr int INF = 0x3f3f3f3f;

int n, m, q, compID[N], siz[N], fir[N], val[N];
vi in[N];

struct Ftree {
private:
    vll t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, ll v) {
        while (i < t.size()) {
            t[i] += v;
            i += i & -i;
        }
    }

    ll qry1(int i) {
        ll s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    ll qry2(int l, int r) {
        return qry1(r) - qry1(l - 1);
    }
} t, t1, t2;

namespace Tarjan {
    int cnt = 0, comp_count = 0;
    int dfn[N], low[N], fa[N];
    vi e[N], tree[N];
    bool vis[N];
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
        fill(compID + 1, compID + n + 1, -1);
        for (int i = 1; i <= n; i++)
            if (compID[i] == -1)
                dfs(i, ++comp_count);
        for (auto it: bridges) {
            int u = compID[it.first], v = compID[it.second];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    inline void main() {
        for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
        build(n);
        fill(fir + 1, fir + n + 1, INF);
        for (int i = 1; i <= n; i++) ++siz[compID[i]], fir[compID[i]] = min(fir[compID[i]], i);
        for (int i = 1; i <= comp_count; i++) if (siz[i] == 1) siz[i] = INF;
        int lx = 0;
        t.init(n + 1), t1.init(n + 1), t2.init(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!--siz[compID[i]]) lx = max(lx, fir[compID[i]]);
            val[i] = i - lx;
            t.upd(i, val[i]);
            in[lx + 1].push_back(i);
        }
    }
}

ll ans[N];
vector<pii> rx[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        Tarjan::e[u].push_back(v);
        Tarjan::e[v].push_back(u);
    }
    cin >> q;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        rx[l].push_back({r, i});
    }
    Tarjan::main();
    // for (int i = 1; i <= n; i++) cout << val[i] << ' ';
    // cout << endl;
    for (int l = 1; l <= n; l++) {
        for (auto [r, qid]: rx[l]) {
            ll val = t.qry2(l, r) + t1.qry2(l, r) - t2.qry2(l, r) * (l - 1);
            ans[qid] = val;
        }
        for (int it: in[l]) {
            t.upd(it, -val[it]);
            t1.upd(it, it);
            t2.upd(it, 1);
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
