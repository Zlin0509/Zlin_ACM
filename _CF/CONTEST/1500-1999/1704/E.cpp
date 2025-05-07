//
// Created by Zlin on 2025/5/7.
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

constexpr int N = 1010;
constexpr ll mo = 998244353;

int n, m, in[N], vis[N];
ll a[N], dep[N];
vi e[N];
vll val[N];

inline void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    bool tag = a[u] == 0;
    for (int v: e[u]) {
        dfs(v);
        dep[u] = max(dep[u], dep[v] + a[v]);
        a[u] += a[v];
    }
    ll dif = -tag;
    for (int v: e[u]) dif = max(dif, dep[u] - dep[v] - tag);
    a[u] -= dif;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in[i] = dep[i] = vis[i] = 0;
        e[i].clear();
        val[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> v >> u;
        e[u].push_back(v);
        ++in[v];
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dfs(i);
            cout << (a[i] + dep[i]) % mo << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
