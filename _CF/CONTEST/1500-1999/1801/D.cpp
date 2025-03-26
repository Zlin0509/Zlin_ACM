//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

constexpr int N = 810;
constexpr ll inf = 1e16;

ll dis[N][N];
int n, m, p;

struct node {
    int val, id;

    bool operator<(const node &x) const {
        if (val != x.val) return val < x.val;
        return id < x.id;
    }
} w[N];

pll ans[N];

inline void Zlin() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        w[i] = {0, 0};
        ans[i] = {inf, 0};
        for (int j = 1; j <= n; j++) {
            dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i].val;
        w[i].id = i;
    }
    sort(w + 1, w + 1 + n);
    for (int i = 1, u, v, s; i <= m; i++) {
        cin >> u >> v >> s;
        dis[u][v] = min(dis[u][v], (ll) s);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    auto update = [&](int id, ll f, ll g) {
        if (f < ans[id].first) ans[id] = {f, g};
        else if (f == ans[id].first && g > ans[id].second) ans[id] = {f, g};
    };
    ans[1] = {0, p};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = w[i].id, y = w[j].id;
            if (dis[x][y] != inf && i != j) {
                auto [f, g] = ans[x];
                if (g >= dis[x][y]) update(y, f, g - dis[x][y]);
                else {
                    ll k = (dis[x][y] - g + w[i].val - 1) / w[i].val;
                    update(y, f + k, g + k * w[i].val - dis[x][y]);
                }
            }
        }
    }
    if (ans[n].first == inf) cout << -1 << endl;
    else cout << ans[n].first << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
