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

constexpr int N = 2e5 + 10;

int n, m, dis[N], vis[N], in[N];
vi e[N];


inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = 2e9;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[v].push_back(u);
        ++in[u];
    }
    dis[n] = 0;
    priority_queue<pii> pq;
    pq.push({-dis[n], n});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: e[u]) {
            int w = in[v]--;
            if (!vis[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
    cout << dis[1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
