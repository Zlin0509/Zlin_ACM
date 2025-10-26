//
// Created by Zlin on 2025/10/23.
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

constexpr int N = 5e5 + 5;

struct BCC {
    int n, T;
    vi dfn, low;
    vector<vi> g;
    vector<pii> stk;
    vector<vector<pii> > E; // 每个bcc里的边
    vector<vi> V; // 每个bcc里的点
    vector<char> cut;

    BCC(int _n = 0) { init(_n); }

    void init(int _n) {
        n = _n;
        T = 0;
        g.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        cut.assign(n + 1, 0);
        stk.clear();
        E.clear();
        V.clear();
    }

    void add(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void tj(int u, int fa) {
        dfn[u] = low[u] = ++T;
        int ch = 0;
        for (int v: g[u]) {
            if (!dfn[v]) {
                stk.emplace_back(u, v);
                tj(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    vector<pii> ed;
                    vi vs;
                    while (true) {
                        auto e = stk.back();
                        stk.pop_back();
                        ed.push_back(e);
                        vs.push_back(e.first);
                        vs.push_back(e.second);
                        if (e.first == u && e.second == v) break;
                    }
                    sort(vs.begin(), vs.end());
                    vs.erase(unique(vs.begin(), vs.end()), vs.end());
                    E.push_back(ed);
                    V.push_back(vs);
                    if (fa != -1 || ++ch > 1) cut[u] = 1;
                }
            } else if (v != fa && dfn[v] < dfn[u]) {
                stk.emplace_back(u, v);
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void build() {
        for (int i = 1; i <= n; i++) if (!dfn[i]) tj(i, -1);
    }
};

int vis[N];
vi e[N];

inline int dfs(int u, int fa) {
    if (vis[u]) return 0;
    vis[u] = 1;
    int ans = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        int tmp = dfs(v, u);
        if (tmp) ans = tmp;
    }
    return ans + 1;
}

inline int dfs(int u, int fa, int tag) {
    if (u == tag) return 1;
    int ans = 0, tmp;
    for (int v: e[u]) {
        if (v == fa) continue;
        tmp = dfs(v, u, tag);
        if (ans && ans != tmp) return -1e9;
        ans = tmp;
    }
    return ans + 1;
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    BCC bcc(n);
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        bcc.add(x, y);
    }
    bcc.build();
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        e[i].clear();
    }
    int ans = 0;
    for (int i = 0; i < bcc.V.size(); i++) {
        const auto &node = bcc.V[i];
        const auto &edge = bcc.E[i];
        if (node.size() < 3) continue;
        for (const auto &[x, y]: edge) {
            e[x].emplace_back(y);
            e[y].emplace_back(x);
        }
        vi top;
        for (const auto &it: node) {
            if (e[it].size() > 2) top.emplace_back(it);
            if (top.size() > 2) {
                cout << "No" << endl;
                return;
            }
        }
        if (top.empty()) {
            int res = dfs(node[0], 0);
            if (ans && ans != res) {
                cout << "No" << endl;
                return;
            }
            ans = res;
        } else {
            int res = dfs(top[0], 0, top[1]);
            if (res < 0 || (ans && ans != res * 2 - 2)) {
                cout << "No" << endl;
                return;
            }
            ans = res * 2 - 2;
        }
        for (const auto &it: node) {
            vis[it] = 0;
            e[it].clear();
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
