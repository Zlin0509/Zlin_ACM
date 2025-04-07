//
// Created by 27682 on 2025/3/31.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;

int son[N], len[N], top[N], dep[N], f[N], val[N][22];
vi e[N];

inline void dfs(int u, int fa) {
    f[u] = fa;
    len[u] = 1;
    for (int v: e[u]) {
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        if (len[u] < len[v] + 1)
            len[u] = len[v] + 1, son[u] = v;
    }
}

inline void dfs1(int u, int fa, int s) {
    top[u] = s;
    if (son[u]) dfs1(son[u], u, s);
    for (int v: e[u]) {
        if (v == fa || v == son[u])
            continue;
        dfs1(v, u, u);
    }
}

inline void Zlin() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        son[i] = len[i] = top[i] = dep[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    int q;
    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        int u = v, ans = len[v];
        while (dep[v] - dep[u] <= k) {
            u = top[u];
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
