//
// Created by 27682 on 2025/3/4.
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

int n, q;
vector<vi> e;
vi c, d;
vi dd;

inline void dfs(int u, int fa) {
    if (c[u] && c[fa])
        d[u]++, d[fa]++;
    for (int v: e[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

inline void Zlin() {
    cin >> n >> q;
    dd.assign(4, 0);
    e.assign(n + 1, vi());
    c.assign(n + 1, 0);
    d.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!c[i]) continue;
        ++dd[min(d[i], 3)];
    }
    while (q--) {
        int u;
        cin >> u;
        c[u] ^= 1;
        if (!c[u])
            --dd[min(d[u], 3)];
        for (int v: e[u]) {
            if (c[u]) {
                if (c[v]) {
                    --dd[min(d[v], 3)];
                    ++d[u], ++d[v];
                    ++dd[min(d[v], 3)];
                }
            } else {
                if (c[v]) {
                    --dd[min(d[v], 3)];
                    --d[u], --d[v];
                    ++dd[min(d[v], 3)];
                }
            }
        }
        if (c[u])
            ++dd[min(d[u], 3)];
        if (dd[0]) {
            cout << (dd[0] == 1 && dd[1] == 0 && dd[2] == 0 && dd[3] == 0 ? "Yes" : "No") << endl;
        } else {
            cout << (dd[1] == 2 && dd[3] == 0 ? "Yes" : "No") << endl;
        }
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