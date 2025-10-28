//
// Created by Zlin on 2025/10/22.
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

constexpr int N = 3e5 + 10;

int n, m, fa[N], son[N], top[N];
ll c[N], val1[N], val2[N], s[N][2];
vi e[N];

int ffa[N][22], dep[N];

inline void dfs(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    ffa[u][0] = f;
    for (int i = 1; i < 22; i++) ffa[u][i] = ffa[ffa[u][i - 1]][i - 1];
    s[u][0] = s[u][1] = 2e9;
    for (int v: e[u]) {
        if (v == f) continue;
        dfs(v, u);
        if (c[v] < s[u][0]) s[u][1] = s[u][0], s[u][0] = c[v], son[u] = v;
        else if (c[v] < s[u][1]) s[u][1] = c[v];
    }
    c[u] = min(c[u], s[u][0] + s[u][1]);
    if (s[u][0] == 2e9) s[u][0] = s[u][1] = 0;
}

inline void dfs1(int u, int t) {
    top[u] = t;
    val1[u] = val1[fa[u]], val2[u] = val2[fa[u]];
    if (!s[u][0]) return;
    val1[u] += s[u][0], val2[u] += s[u][1];
    if (son[u]) dfs1(son[u], t);
    for (int v: e[u]) {
        if (v == son[u] || v == fa[u]) continue;
        dfs1(v, v);
    }
}

inline ll query(int x, int y) {
    ll ans = 0;
    while (top[x] != top[y]) {
        ans += val2[x] - val2[top[x]] - s[x][1] + s[top[x]][1];
        x = top[x];
        ans += s[fa[x]][0];
        x = fa[x];
    }
    ans += val2[x] - val2[y] - s[x][1] + s[y][1];
    return ans;
}

int find(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 21; ~i; i--) if (dep[ffa[u][i]] >= dep[v]) u = ffa[u][i];
    if (u == v) return u;
    for (int i = 21; ~i; i--) if (ffa[u][i] != ffa[v][i]) u = ffa[u][i], v = ffa[v][i];
    return ffa[u][0];
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        fa[i] = son[i] = top[i] = 0;
        val1[i] = val2[i] = 0;
        for (int j = 0; j < 22; j++) ffa[i][j] = 0;
        e[i].clear();
    }
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1, 0);
    dfs1(1, 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (find(x, y) != y) cout << -1 << endl;
        else cout << query(x, y) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
