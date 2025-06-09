//
// Created by 27682 on 2025/6/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 210;
constexpr ll mo = 1e9 + 7;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll inv2, val[N][N], ans;
int n, f[N][19], dep[N], len[N];
vi e[N];

inline void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < 9; i++) f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

inline int Lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 8; ~i; i--)
        if (dep[f[u][i]] >= dep[v])
            u = f[u][i];
    if (u == v) return u;
    for (int i = 8; ~i; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

inline void Zlin() {
    inv2 = qpow(2, mo - 2);
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (!x) val[x][y] = 1;
            else if (!y) val[x][y] = 0;
            else val[x][y] = (val[x - 1][y] + val[x][y - 1]) % mo * inv2 % mo;
        }
    }
    for (int s = 1; s <= n; s++) {
        dfs(s, 0);
        for (int j = 1; j <= n; j++) {
            for (int i = j + 1; i <= n; i++) {
                int lca = Lca(i, j);
                ans = (ans + val[dep[i] - dep[lca]][dep[j] - dep[lca]]) % mo;
            }
        }
    }
    ans = ans * qpow(n, mo - 2) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
