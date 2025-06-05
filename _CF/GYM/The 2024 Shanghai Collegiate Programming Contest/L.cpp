//
// Created by Zlin on 2025/5/22.
//

#include "bits/stdc++.h"
#define endl "\n"
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

constexpr int N = 5e5 + 10;

int n, m, k;
int c[N], val[N];
vi e[N], g[N];

inline void dfs(int u) {
    if (e[u].empty()) return;
    for (int v: e[u]) dfs(v);
    for (int v: g[u]) val[u] = min(val[u], val[v] + 1);
    int mx = 0;
    for (int v: e[u]) {
        mx += val[v];
        if (mx >= val[u]) break;
    }
    val[u] = min(val[u], mx);
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
        val[i] = 2e6;
        e[i].clear();
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 1, x; j <= c[i]; j++) {
            cin >> x;
            e[i].push_back(x);
        }
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        val[x] = 0;
    }
    dfs(1);
    cout << (val[1] == 2e6 ? -1 : val[1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
