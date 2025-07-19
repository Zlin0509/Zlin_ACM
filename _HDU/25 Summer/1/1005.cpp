//
// Created by 27682 on 2025/7/18.
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

constexpr int N = 1e5 + 10;
constexpr ll inf = 1e18;

int n, m;

struct edge {
    int v, op;
};

vector<edge> e[N];

int vis[N];

ll dis[N];
map<int, int> mp[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        mp[i].clear();
        vis[i] = 0;
        dis[i] = inf;
    }
    for (int i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }
    priority_queue<pll, vector<pll>, greater<> > pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, c]: e[u]) {
            if (mp[u].count(c)) {
                if (dis[v] > dis[u]) {
                    mp[v].clear();
                    mp[v][c] = 1;
                    dis[v] = dis[u];
                    pq.emplace(dis[v], v);
                } else if (dis[v] == dis[u]) mp[v][c] = 1;
            } else {
                if (dis[v] > dis[u] + 1) {
                    mp[v].clear();
                    mp[v][c] = 1;
                    dis[v] = dis[u] + 1;
                    pq.emplace(dis[v], v);
                } else if (dis[v] == dis[u] + 1) mp[v][c] = 1;
            }
        }
    }
    cout << dis[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
