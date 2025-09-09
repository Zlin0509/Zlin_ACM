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
constexpr int inf = 1e8;

int n, m, dis[N], tmp[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        dis[i] = tmp[i] = inf;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dis[1] = 0;
    for (int x = 0; ; x++) {
        if (dis[n] != inf) {
            cout << x << ' ' << dis[n] << endl;
            return;
        }
        for (int i = 1; i <= n; i++) tmp[e[i][x % e[i].size()]] = min(tmp[e[i][x % e[i].size()]], dis[i]);
        for (int i = 1; i <= n; i++) tmp[i] = min(tmp[i], dis[i] + 1);
        for (int i = 1; i <= n; i++) dis[i] = tmp[i], tmp[i] = inf;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
