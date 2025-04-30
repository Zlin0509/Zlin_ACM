//
// Created by Zlin on 2025/4/20.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;
constexpr ll inf = 2e14;

int n, m;

struct edge {
    ll v, val;
};

vector<edge> e[N];
ll val[N][22], vis[N], dis[N], len[N], idx[N];

inline void dij(int s, int id) {
    priority_queue<pll> pq;
    dis[s] = 0;
    pq.push({-dis[s], s});
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        idx[u] = id;
        for (auto [v, va]: e[u]) {
            for (int i = 0; i <= min(len[u], len[v]); i++) val[v][i] = min(val[v][i], val[u][i] + va);
            if (dis[v] > dis[u] + va) {
                dis[v] = dis[u] + va;
                pq.push({-dis[v], v});
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int lx = 1;
        while (lx <= i) {
            ++len[i];
            lx <<= 1;
        }
        dis[i] = inf;
        for (int j = 0; j < 22; j++) val[i][j] = inf;
        val[i][len[i]] = 0;
    }
    for (int i = 1, u, v, va; i <= m; i++) {
        cin >> u >> v >> va;
        e[u].push_back({v, va});
        e[v].push_back({u, va});
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dij(i, i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t, lx = 0;
        cin >> s >> t;
        if (idx[s] != idx[t]) {
            cout << -1 << endl;
            continue;
        }
        ll ans = inf;
        while (lx < min(len[s], len[t]) && s / (1 << len[s] - lx - 1) == t / (1 << len[t] - lx - 1)) {
            ++lx;
            ans = min(ans, val[s][lx] + val[t][lx]);
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
