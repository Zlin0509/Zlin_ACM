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

int n, m;
ll c[N], mx[N][2];
ll fa[N][20], dep[N], val[N][20];
vi e[N];

inline void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    mx[u][0] = mx[u][1] = 2e9;
    for (int v: e[u]) {
        if (v == f) continue;
        dfs(v, u);
        if (c[v] < mx[u][0]) {
            mx[u][1] = mx[u][0];
            mx[u][0] = c[v];
        } else if (c[v] < mx[u][1]) {
            mx[u][1] = c[v];
        }
    }
    c[u] = min(c[u], mx[u][0] + mx[u][1]);
}

inline void dfs1(int u, int f) {
    if (c[u] == mx[f][0]) val[u][0] = mx[f][1];
    else val[u][0] = mx[f][0];
    for (int i = 1; i < 22; i++) val[u][i] = val[fa[u][i - 1]][i - 1] + val[u][i - 1];
    for (int v: e[u]) {
        if (v == f) continue;
        dfs1(v, u);
    }
}

inline int find(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 21; ~i; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 21; ~i; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 0; j < 22; j++) fa[i][j] = val[i][j] = 0;
        e[i].clear();
    }
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    dfs(1, 0);
    for (int v: e[1]) dfs1(v, 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (find(x, y) != y) cout << -1 << endl;
        else {
            ll ans = 0;
            for (int i = 21; ~i; i--) {
                if (dep[fa[x][i]] >= dep[y]) {
                    ans += val[x][i];
                    x = fa[x][i];
                }
            }
            cout << ans << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
