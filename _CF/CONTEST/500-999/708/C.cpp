//
// Created by 27682 on 2025/7/4.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int N = 4e5 + 10;

int n, siz1[N], siz2[N], ans[N], mx[N], siz[N], nxt1[N], nxt2[N];
vi e[N];

inline void dfs(int u, int fa) {
    siz[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        mx[u] = max(mx[u], siz[v]);
        if (siz[v] <= n / 2) {
            if (siz[v] > siz1[u]) {
                siz2[u] = siz1[u];
                nxt2[u] = nxt1[u];
                siz1[u] = siz[v];
                nxt1[u] = v;
            } else if (siz[v] > siz2[u]) {
                siz2[u] = siz[v];
                nxt2[u] = v;
            }
        } else {
            if (siz1[v] > siz1[u]) {
                siz2[u] = siz1[u];
                nxt2[u] = nxt1[u];
                siz1[u] = siz1[v];
                nxt1[u] = v;
            } else if (siz1[v] > siz2[u]) {
                siz2[u] = siz1[v];
                nxt2[u] = v;
            } else if (siz2[v] > siz1[u]) {
                siz2[u] = siz1[u];
                nxt2[u] = nxt1[u];
                siz1[u] = siz2[v];
                nxt1[u] = v;
            } else if (siz2[v] > siz2[u]) {
                siz2[u] = siz2[v];
                nxt2[u] = v;
            }
        }
    }
    mx[u] = max(mx[u], n - siz[u]);
}

inline void dfs1(int u, int fa, int val) {
    if (mx[u] <= n / 2) ans[u] = 1;
    else if (n - siz[u] <= n / 2) {
        for (int v: e[u]) {
            if (siz[v] > n / 2 && siz[v] - siz1[v] <= n / 2) {
                ans[u] = 1;
                break;
            }
        }
    } else if (mx[u] - val <= n / 2) ans[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        int tval = val;
        if (n - siz[u] <= n / 2) tval = max(tval, n - siz[u]);
        if (nxt1[u] != v) tval = max(tval, siz1[u]);
        else tval = max(tval, siz2[u]);
        dfs1(v, u, tval);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
