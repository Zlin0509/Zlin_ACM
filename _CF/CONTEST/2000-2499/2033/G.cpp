//
// Created by Zlin on 2025/4/3.
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

constexpr int N = 2e5 + 10;

int n, f[N][22], val[N][22], m1[N], m2[N], len[N], dep[N];
vi e[N];

inline void dfs(int u, int fa) {
    len[u] = m1[u] = m2[u] = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        if (len[v] >= m1[u]) {
            m2[u] = m1[u];
            m1[u] = len[v] + 1;
        } else if (len[v] >= m2[u]) {
            m2[u] = len[v] + 1;
        }
    }
    len[u] = m1[u];
    for (int v: e[u]) {
        if (v == fa) continue;
        if (len[v] + 1 == m1[u])
            val[v][0] = m2[u];
        else
            val[v][0] = m1[u];
    }
}

inline void dfs1(int u, int fa) {
    for (int v: e[u]) {
        if (v == fa) continue;

        f[v][0] = u;
        for (int i = 1; i < 22; i++) {
            f[v][i] = f[f[v][i - 1]][i - 1];
            val[v][i] = max(val[v][i - 1], val[f[v][i - 1]][i - 1] + (1 << i - 1));
        }

        dfs1(v, u);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        m1[i] = m2[i] = 0;
        dep[i] = len[i] = 0;
        for (int j = 0; j < 22; j++)
            f[i][j] = val[i][j] = 0;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int v, k;
        cin >> v >> k;
        k = min(k, dep[v]);
        int ans = max(k, len[v]),lst = 1;
        for (int i = 20; ~i; i--) {
            if (k < 1 << i) continue;
            k -= 1 << i;
            ans = max(ans , val[v][i] + lst);
            v = f[v][i];
            lst += 1 << i;
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
