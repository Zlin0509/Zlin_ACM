//
// Created by 27682 on 2025/5/21.
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

constexpr int N = 3010;

int n, m, dis[N], in[N], lst[N], vis[N];

struct edge {
    int v, val;
};

vector<edge> e[N];

vi g[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1, l; i <= n; i++) {
        cin >> l;
        in[i] = l;
        for (int j = 0, v; j < l; j++) {
            cin >> v;
            g[v].push_back(i);
        }
    }
    dis[1] = 0;
    priority_queue<pii> pq;
    pq.push({-dis[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: g[u]) {
            --in[v];
            lst[v] = max(lst[v], dis[u]);
            dis[v] = max(dis[v], lst[v]);
            if (!in[v]) pq.push({-dis[v], v});
        }
        for (auto [v, w]: e[u]) {
            if (max(lst[v], dis[u] + w) < dis[v]) {
                dis[v] = max(lst[v], dis[u] + w);
                if (!in[v]) pq.push({-dis[v], v});
            }
        }
    }
    cout << dis[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
