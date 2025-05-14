//
// Created by Zlin on 2025/5/11.
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
constexpr ll mo = 998244353;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

int n, len[N], son[N];
vi e[N];
ll val[N], k[N];

inline void dfs(int u, int fa) {
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (len[v] < len[u]) {
            len[u] = len[v];
            son[u] = v;
        }
    }
    if (len[u] == 2e9) k[u] = len[u] = 0;
    else k[u] = qpow((2 - k[son[u]] + mo) % mo, mo - 2);
    len[u]++;
}

inline void dfs1(int u, int fa) {
    if (!son[u]) return;
    val[u] = k[u] * val[fa] % mo;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs1(v, u);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        val[i] = son[i] = 0;
        len[i] = 2e9;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    val[1] = 1;
    for (int v: e[1]) dfs1(v, 1);
    for (int i = 1; i <= n; i++) cout << val[i] << ' ';
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
