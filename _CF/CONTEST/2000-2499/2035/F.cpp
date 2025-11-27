//
// Created by 27682 on 2025/11/25.
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

constexpr int N = 2020;

int n, x;
ll f[N], g[N], a[N], idx[N], fa[N];
vi e[N];

int cnt = 0;

inline void dfs(int u, int f) {
    idx[++cnt] = u;
    fa[u] = f;
    for (int v: e[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
}

inline bool cal(ll val) {
    for (int i = 1; i <= n; i++) {
        g[i] = a[i];
        f[i] = val / n + (i <= val % n);
    }
    f[0] = g[0] = 0;
    for (int i = n; i; i--) {
        ll u = idx[i];
        g[fa[u]] += f[u] < g[u] ? g[u] - f[u] : f[u] - g[u] & 1;
    }
    return g[0] == 0;
}

inline void Zlin() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    cnt = 0;
    dfs(x, 0);
    ll ans = 1e18;
    for (int i = 0; i <= n * 2; i++) {
        ll l = 0, r = 1e9, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (cal(2ll * n * mid + i)) r = mid;
            else l = mid + 1;
        }
        ans = min(ans, 2ll * n * l + i);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
