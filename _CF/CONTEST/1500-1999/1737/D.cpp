//
// Created by Zlin on 2025/5/1.
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

constexpr int N = 510;
constexpr ll inf = 2e18;

struct edge {
    ll u, v, w;
};

int T, n, m;
ll dis[N][N];
edge e[N * N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = inf * (i != j);
    for (int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, e[i] = {u, v, w}, dis[u][v] = dis[v][u] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    ll ans = inf;
    for (int i = 1; i <= m; i++) {
        ll u = e[i].u, v = e[i].v, cur = min(dis[u][1] + dis[v][n], dis[v][1] + dis[u][n]);
        for (int k = 1; k <= n; k++) cur = min(cur, min(dis[u][k], dis[v][k]) + 1 + dis[k][1] + dis[k][n]);
        ans = min(ans, (cur + 1) * e[i].w);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
