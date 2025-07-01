//
// Created by 27682 on 2025/7/1.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int N = 1e5 + 10;

int n, m, vis[N];

struct edge {
    int v, val;
};

vector<edge> e[N];

struct LinearBasis {
    ll basis[62];
    bool zero;

    LinearBasis() {
        memset(basis, 0, sizeof(basis));
        zero = false;
    }

    bool insert(ll x) {
        for (int i = 60; ~i; i--) {
            if (x >> i & 1) {
                if (!basis[i]) {
                    basis[i] = x;
                    return true;
                }
                x ^= basis[i];
            }
        }
        zero = true;
        return false;
    }

    ll cal(ll res) {
        for (int i = 60; ~i; i--) if (res >> i & 1) res ^= basis[i];
        return res;
    }
} linear;

ll dis[N];

inline void dfs(int u, int fa) {
    vis[u] = 1;
    for (auto [v, val]: e[u]) {
        if (v != fa) {
            if (!vis[v])dis[v] = dis[u] ^ val, dfs(v, u);
            else linear.insert(val ^ dis[u] ^ dis[v]);
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << linear.cal(dis[1] ^ dis[n]) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
