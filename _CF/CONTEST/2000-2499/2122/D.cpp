//
// Created by 27682 on 2025/8/31.
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

constexpr int N = 5001;
constexpr ll inf = 1e8;

int n, m, dis1[N][N], dis2[N][N];
bool vis[N][N];
vi e[N];

struct Node {
    int dis1, dis2, u;

    bool operator<(const Node &b) const {
        if (dis1 != b.dis1) return dis1 > b.dis1;
        return dis2 > b.dis2;
    }
};

inline void dij() {
    priority_queue<Node> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            dis1[i][j] = dis2[i][j] = inf;
            vis[i][j] = 0;
        }
    }
    dis1[1][0] = dis2[1][0] = 0;
    pq.emplace(dis1[1][0], dis2[1][0], 1);
    while (!pq.empty()) {
        auto [ux, zz, u] = pq.top();
        pq.pop();
        int uux = ux % e[u].size();
        if (vis[u][uux]) continue;
        vis[u][uux] = 1;
        for (int vx = 0, v, vvx, d1, d2; vx < e[u].size(); vx++) {
            d1 = ux + vx - uux, d2 = zz + vx - uux;
            if (uux > vx) d1 += e[u].size(), d2 += e[u].size();

            vvx = d1 % e[u].size();
            if (d1 < dis1[u][vvx] || (d1 == dis1[u][vvx] && d2 < dis2[u][vvx])) {
                dis1[u][vvx] = d1, dis2[u][vvx] = d2;
                pq.emplace(dis1[u][vvx], dis2[u][vvx], u);
            }

            v = e[u][vx];
            vvx = ++d1 % e[v].size();
            if (d1 < dis1[v][vvx] || (d1 == dis1[v][vvx] && d2 < dis2[v][vvx])) {
                dis1[v][vvx] = d1, dis2[v][vvx] = d2;
                pq.emplace(dis1[v][vvx], dis2[v][vvx], v);
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dij();
    int ans1 = inf, ans2 = 0;
    for (int i = 0; i < e[n].size(); i++) {
        if (dis1[n][i] < ans1 || (dis1[n][i] == ans1 && dis2[n][i] < ans2)) {
            ans1 = dis1[n][i];
            ans2 = dis2[n][i];
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
