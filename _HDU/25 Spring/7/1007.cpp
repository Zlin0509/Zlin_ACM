//
// Created by 27682 on 2025/4/18.
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

struct edge {
    int v;
    ll val;
};

vector<edge> e[N], g[N];
int n, s, t, tag[N];
vi now;
ll ans;

inline void dfs1(int u, int fa, ll sum) {
    now.push_back(u);
    if (u == t) {
        ans = sum;
        for (int it: now) tag[it] = 1;
    }
    if (tag[t]) return;
    for (auto [v, val]: e[u]) {
        if (v == fa) continue;
        dfs1(v, u, sum + val);
    }
    now.pop_back();
}

inline ll dfs2(int u, int fa) {
    ll res = 0;
    for (auto [v, val]: g[u]) {
        if (v == fa || tag[v]) continue;
        res += max(dfs2(v, u) + val, 0ll);
    }
    return res;
}

inline void Zlin() {
    cin >> n;
    now.clear();
    for (int i = 1; i <= n; i++) {
        tag[i] = 0;
        e[i].clear(), g[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        ll p, q;
        cin >> u >> v >> p >> q;
        e[u].push_back({v, p});
        e[v].push_back({u, q});
        g[u].push_back({v, p + q});
        g[v].push_back({u, p + q});
    }
    cin >> s >> t;
    dfs1(s, 0, 0);
    for (int i = 1; i <= n; i++)
        if (tag[i])
            ans += dfs2(i, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
