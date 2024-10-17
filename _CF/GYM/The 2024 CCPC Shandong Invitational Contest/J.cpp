//
// Created by Zlin on 2024/10/7.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 1010;
ll n, c[N], b[N][N], f[N], ans;
const ll inf = INT_MAX;

struct edge {
    ll v, w;
};
vector<edge> e[N];
ll d[N], vis[N];

void prim(int s) {
    for (int i = 0; i <= n; i++)
        d[i] = inf;
    d[s] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        ans += d[u];
        for (auto ed: e[u]) {
            ll v = ed.v, w = ed.w;
            if (d[v] > w) {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i], f[i] = inf, vis[i] = 0, e[i].clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
            f[i] = min(f[i], b[i][j]);
            if (i != j)
                e[i].push_back({j, b[i][j]});
        }
    ans = 0;
    prim(1);
    for (int i = 1; i <= n; i++)
        ans += f[i] * (c[i] - 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}