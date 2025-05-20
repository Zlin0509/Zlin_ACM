//
// Created by Zlin on 2025/4/13.
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

constexpr int N = 5010;

int n, m, c, ans = 0, cnt = 0;

struct edge {
    int v, val;
};

int vis[N], dis[N];
vector<edge> e[N];

inline bool dij(int s) {
    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = 2e9;
    }
    dis[s] = 0, vis[s] = 1;
    for (auto [v, val]: e[s]) {
        if (val > c) continue;
        dis[v] = val;
        pq.push({-dis[v], v});
    }
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, val]: e[u]) {
            if (dis[u] + val <= c && v == s)
                return true;
            if (dis[u] + val > c || dis[u] + val >= dis[v])
                continue;
            dis[v] = dis[u] + val;
            pq.push({-dis[v], v});
        }
    }
    return false;
}

inline void Zlin() {
    cin >> n >> m >> c;
    for (int i = 0, u, v, val; i < m; i++) {
        cin >> u >> v >> val;
        e[u].push_back({v, val});
        if (val <= c) ans = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (dij(i)) {
            ans = 2;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
