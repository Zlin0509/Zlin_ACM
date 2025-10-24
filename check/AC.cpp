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

vector<vi> g, tg;

struct BCT {
    int n, tot, ts; // n 原图点数, tot 圆方树总点数
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
                    // 新建一个 BCC 节点
                    vector<int> bcc;
                    while (true) {
                        int x = st.back();
                        st.pop_back();
                        bcc.push_back(x);
                        if (x == v) break;
                    }
                    bcc.push_back(u);
                    // 仅当 BCC 中点数 > 2 或者形成环才加入圆方树
                    if (bcc.size() > 2) {
                        ++tot;
                        tg.resize(tot + 1);
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
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                st.clear();
                tarjan(i, -1);
            }
        }
    }
} bct;

constexpr int N = 5e5 + 5;

int n, m, val[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    bct.init(n);
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        bct.add(x, y);
    }
    bct.build();
    vi idx;
    for (int i = n + 1; i <= bct.tot; i++) idx.emplace_back(i);
    ll check = 0;
    sort(idx.begin(), idx.end(), [&](int i, int j) { return tg[i].size() > tg[j].size(); });
    for (const int &id: idx) {
        vi node;
        for (const int &v: tg[id]) {
            node.emplace_back(v);
            val[v] = 1;
        }
        for (const int &u: node) {
            sort(g[u].begin(), g[u].end(), [&](int i, int j) { return val[i] < val[j]; });
            int si = g[u].size();
            check += si * log2(si);
            while (!g[u].empty() && val[g[u].back()]) {
                e[u].emplace_back(g[u].back());
                g[u].pop_back();
                ++check;
            }
        }
        for (const int &it: node) {
            e[it].clear();
            val[it] = 0;
        }
    }
    if (check > 1ll * n * log2(n) * 10) cout << check << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
