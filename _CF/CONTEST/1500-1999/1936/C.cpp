//
// Created by 27682 on 2025/7/5.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;

constexpr int N = 9e5 + 10;
constexpr ll INF = 1e15;

int n, m, vis[N];
ll dis[N];
vi a[N];

struct edge {
    int v, val;
};

vector<edge> e[N];

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i <= n * (m + 1); i++) {
        dis[i] = INF, vis[i] = 0;
        e[i].clear();
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 1; j <= m; j++) {
            e[i].emplace_back(i + j * n, 0);
            e[i + j * n].emplace_back(i, x);
        }
    }
    for (int i = 0; i < n; i++) {
        a[i].assign(m + 1, 0);
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int j = 1; j <= m; j++) {
        vi idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int x, int y) {
            return a[x][j] < a[y][j];
        });
        for (int i = 0; i < n - 1; i++) {
            e[idx[i] + j * n].emplace_back(idx[i + 1] + j * n, 0);
            e[idx[i + 1] + j * n].emplace_back(idx[i] + j * n, a[idx[i + 1]][j] - a[idx[i]][j]);
        }
    }
    dis[0] = 0;
    pq.emplace(dis[0], 0);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, val]: e[u]) {
            if (dis[v] > dis[u] + val) {
                dis[v] = dis[u] + val;
                pq.emplace(dis[v], v);
            }
        }
    }
    cout << dis[n - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
