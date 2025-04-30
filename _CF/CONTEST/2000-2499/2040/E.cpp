//
// Created by 27682 on 2025/3/3.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;

int n, q;
vector<vi> e;
vi fa, ffa;

inline void dfs(int u, int f) {
    fa[u] = f;
    ffa[u] = fa[f];
    for (int v: e[u]) {
        if (v == f)
            continue;
        dfs(v, u);
    }
}

inline void Zlin() {
    cin >> n >> q;
    e.assign(n + 1, vi());
    fa.assign(n + 1, 0);
    ffa.assign(n + 1, 0);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int v, p;
        cin >> v >> p;
        vll now;
        while (fa[v] && ffa[v]) {
            now.push_back(e[fa[v]].size() * 2);
            v = ffa[v];
        }
        sort(now.begin(), now.end());
        ll ans = 0;
        while (!now.empty() && p-- && now.back() > 2)
            now.pop_back(), ans += 2;
        for (int it: now)
            ans += it;
        ans += v != 1;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}