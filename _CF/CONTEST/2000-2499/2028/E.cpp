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

int n, in[N], f[N];
vi e[N];
ll val[N];

inline void dfs(int u, int fa) {
    f[u] = fa;
    for (int v: e[u]) {
        if (v == fa) continue;
        ++in[u];
        dfs(v, u);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        val[i] = 0;
        in[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            val[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = f[u];
        val[v] = max(val[v], val[u] * 2);
        if (!--in[v]) q.push(v);
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << 1 << ' ';
        } else {
            cout << (1 - qpow(val[i], mo - 2) + mo) % mo << ' ';
        }
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
