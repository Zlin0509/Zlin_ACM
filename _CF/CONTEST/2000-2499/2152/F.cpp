//
// Created by 27682 on 2025/11/5.
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

constexpr int N = 3e5;

int n, z, a[N], q;
vi e[N];

int fa[N][22], dep[N];

inline void dfs(int u, int ffa) {
    dep[u] = dep[ffa] + 1;
    fa[u][0] = ffa;
    for (int i = 1; i < 22; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v: e[u]) dfs(v, u);
}

inline int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 21; ~i; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 21; ~i; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int lca[N][22], val[N][22];

inline void Zlin() {
    cin >> n >> z;
    for (int i = 0; i <= n; i++) e[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, tag = 1; i <= n; i++) {
        while (tag <= n && a[tag] - a[i] <= z) ++tag;
        if (tag <= n) e[tag].emplace_back(i);
        else e[0].emplace_back(i);
    }
    dfs(0, 0);
    for (int i = 1; i < n; i++) {
        lca[i][0] = LCA(i, i + 1);
        val[i][0] = dep[i] + dep[i + 1] - dep[lca[i][0]] * 2;
    }
    for (int j = 1; j < 22; j++) {
        for (int i = 1; i < n; i++) {
            lca[i][j] = lca[lca[i][j - 1]][j - 1];
            val[i][j] = val[i][j - 1] + val[lca[i][j - 1]][j - 1];
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r - l <= 1) {
            cout << r - l + 1 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 21; ~i; i--) {
            if (lca[l][i] && lca[l][i] <= r) {
                ans += val[l][i];
                l = lca[l][i];
            }
        }
        if (l == r) {
            cout << ans + 1 << endl;
            continue;
        }
        int l1 = l, l2 = l + 1;
        for (int i = 21; ~i; i--) {
            if (fa[l1][i] && fa[l1][i] <= r) l1 = fa[l1][i];
            if (fa[l2][i] && fa[l2][i] <= r) l2 = fa[l2][i];
        }
        cout << ans + dep[l] - dep[l1] + 1 + dep[l + 1] - dep[l2] + 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
