//
// Created by 27682 on 2025/7/4.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

constexpr int N = 1010;
constexpr ll INF = 1e12;

int n, m, vis[N], L, s, t;
ll dis[N];

struct line {
    int u, v, w;
} line[N * 11];

vi e[N];

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

inline void dij1() {
    fill(vis, vis + n, 0);
    fill(dis, dis + n, INF);
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int id: e[u]) {
            auto [ux, vx, w] = line[id];
            int v;
            if (vx == u) v = ux;
            else v = vx;
            if (!w || dis[v] < dis[u] + w) continue;
            dis[v] = dis[u] + w;
            pq.emplace(dis[v], v);
        }
    }
}

int pre[N];

inline void dij2() {
    fill(vis, vis + n, 0);
    fill(dis, dis + n, INF);
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        int u = pq.top().second;;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int id: e[u]) {
            auto [ux, vx, w] = line[id];
            int v;
            if (vx == u) v = ux;
            else v = vx;
            if (!w) w = 1;
            if (dis[v] < dis[u] + w) continue;
            pre[v] = u;
            dis[v] = dis[u] + w;
            pq.emplace(dis[v], v);
        }
    }
}

inline void dfs(int u, int dif) {
    if (u == s) return;
    int v = pre[u];
    for (int id: e[u]) {
        auto [ux, vx, w] = line[id];
        if (ux == v || vx == v) {
            if (!w) {
                line[id].w = 1;
                if (dif) line[id].w += dif, dif = 0;
            }
            dfs(v, dif);
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> L >> s >> t;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        line[i] = {u, v, w};
        e[u].push_back(i);
        e[v].push_back(i);
    }
    dij1();
    if (dis[t] < L) {
        cout << "NO" << endl;
        return;
    }
    dij2();
    if (dis[t] > L) {
        cout << "NO" << endl;
        return;
    }
    dfs(t, L - dis[t]);
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) cout << line[i].u << ' ' << line[i].v << ' ' << (line[i].w ? line[i].w : INF) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
