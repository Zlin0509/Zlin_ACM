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
    vll lx(n + 1), rx(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lx[i] >> rx[i];
    vector e(n + 1, vi());
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll ans = 0;
    vll f(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
        ll mx = 0;
        for (int v: e[u]) {
            if (v == fa) continue;
            dfs(v, u);
            mx = max(mx, f[v]);
        }
        if (mx <= rx[u]) f[u] = max(lx[u], mx);
        else {
            f[u] = rx[u];
            for (int v: e[u])
                if (v != fa)
                    ans += max(0ll, f[v] - f[u]);
        }
    };
    dfs(1, 0);
    cout << ans + f[1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
