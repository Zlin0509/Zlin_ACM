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
    int u, v;
    ll w;
} line[N * 11];

vi e[N];

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

inline void dij() {
    fill(vis, vis + n, 0);
    fill(dis, dis + n, INF);
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        int u = pq.top().second, v;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int id: e[u]) {
            auto [ux, vx, val] = line[id];
            v = ux == u ? vx : ux;
            if (dis[v] > dis[u] + val) {
                dis[v] = dis[u] + val;
                pq.emplace(dis[v], v);
            }
        }
    }
}

inline void out() {
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) cout << line[i].u << ' ' << line[i].v << ' ' << line[i].w << endl;
}

inline void Zlin() {
    cin >> n >> m >> L >> s >> t;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        line[i] = {u, v, w};
        if (!line[i].w) line[i].w = INF;
        e[u].push_back(i);
        e[v].push_back(i);
    }
    dij();
    if (dis[t] < L) {
        cout << "NO" << endl;
        return;
    }
    if (dis[t] == L) {
        out();
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (line[i].w == INF) {
            line[i].w = 1;
            dij();
            if (dis[t] <= L) {
                line[i].w += L - dis[t];
                out();
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
