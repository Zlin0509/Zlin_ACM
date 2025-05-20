//
// Created by 27682 on 2025/5/19.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int long long
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

constexpr int N = 2e5 + 10;

int n, m, H, l[N], s[N], vis[N];
int dis[N];
vi e[N];

inline void dij() {
    dis[1] = 0;
    priority_queue<pii> pq;
    pq.push({-dis[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: e[u]) {
            int x, y, g = exgcd((s[u] - s[v] + H) % H, H, x, y), t = abs(H / g);
            if ((l[v] - l[u]) % g) continue;
            x *= (l[v] - l[u]) / g;
            x = (x % t + t) % t;
            if (x < dis[u]) x += (dis[u] - x + t - 1) / t * t;
            if (dis[v] > x + 1) {
                dis[v] = x + 1;
                pq.push({-dis[v], v});
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> H;
    for (int i = 1; i <= n; i++) {
        dis[i] = 2e18;
        vis[i] = 0;
        e[i].clear();
    }
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dij();
    cout << (dis[n] == 2e18 ? -1 : dis[n]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
