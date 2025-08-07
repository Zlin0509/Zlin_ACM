//
// Created by Zlin on 2025/8/7.
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

constexpr int N = 2e5 + 10;
constexpr int mo = 1e9 + 7;

int n, m, k;
int val[N], mx[N];

struct node {
    int x, y;

    bool operator<(const node &b) const {
        return x > b.x;
    }
};

struct edge {
    int u, v, w;

    bool operator<(const edge &b) const {
        return w < b.w;
    }
} e[N];

int f[N], siz[N], vis[N], cnt;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    --cnt;
    f[fx] = fy;
    siz[fy] += siz[fx];
}

inline void Zlin() {
    cin >> n >> m >> k;
    cnt = n;
    for (int i = 1; i <= n; i++) val[i] = 1e9, f[i] = i;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        val[u] = min(val[u], w);
        val[v] = min(val[v], w);
        merge(u, v);
    }
    if (cnt > 2) {
        cout << 0 << endl;
        return;
    }
    if (cnt == 2) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (find(i) == find(1)) ++cnt;
        cout << 1ll * cnt * (n - cnt) % mo * k % mo << endl;
        return;
    }
    sort(e + 1, e + m + 1);
    sort(val + 1, val + n + 1);
    ll ans = 0, sum = 0;
    for (int i = n; i; i--) {
        ans = (ans + sum - val[i] * (n - i)) % mo;
        sum += val[i];
    }
    int lx = 1, rx = 1;
    while (lx <= m) {
        while (rx + 1 <= m && e[rx + 1].w == e[lx].w) ++rx;
        for (int i = lx; i <= rx; i++) {
            f[e[i].u] = e[i].u;
            siz[e[i].u] = 1;
            vis[e[i].u] = 0;
            f[e[i].v] = e[i].v;
            siz[e[i].v] = 1;
            vis[e[i].v] = 0;
        }
        for (int i = lx; i <= rx; i++) merge(e[i].u, e[i].v);
        for (int i = lx; i <= rx; i++) {
            int idx = find(e[i].u);
            if (!vis[idx]) {
                vis[idx] = 1;
                ans = (ans + (rx - lx + 1 - siz[idx]) * (e[lx].w - 1)) % mo;
            }
        }
        lx = rx + 1;
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
