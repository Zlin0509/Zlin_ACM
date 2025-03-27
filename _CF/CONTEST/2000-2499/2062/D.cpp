//
// Created by Zlin on 2025/3/27.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi lx(n + 1), rx(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lx[i] >> rx[i];
    vector e(n + 1, vi());
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0, tot = 0;
    auto dfs = [&](auto &&dfs, int u, int pre, int l, int r) {
        vis[u] = 1;
        ans = max(ans, l);
        for (int v: e[u]) {
            if (vis[v]) continue;
            if (r < lx[v] + tot - pre) {
                int dif = lx[v] + tot - pre - r;
                tot += dif;
                dfs(dfs, v, pre + dif, lx[v] + pre, lx[v] + pre);
            } else if (l > rx[v] + tot - pre) {
                dfs(dfs, v, pre + rx[v] + pre - l, l, l);
            } else {
            }
        }
    };
    dfs(dfs, 1, 0, lx[1], rx[1]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
