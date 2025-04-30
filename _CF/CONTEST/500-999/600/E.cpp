//
// Created by 27682 on 2025/3/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef __int128 i128;
typedef long long i64;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<i64> vll;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;

constexpr int N = 1e5 + 10;

int n;
int c[N], son[N], siz[N];
vi e[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    int mx = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > mx) mx = siz[v], son[u] = v;
    }
}

i64 ans[N], cnt[N];
i64 mx = 0, val = 0;

void add(int u, int fa, int son) {
    ++cnt[c[u]];
    if (cnt[c[u]] > mx) mx = cnt[c[u]], val = c[u];
    else if (cnt[c[u]] == mx) val += c[u];
    for (int v: e[u]) {
        if (v == fa || v == son) continue;
        add(v, u, son);
    }
}

void del(int u, int fa) {
    --cnt[c[u]];
    for (int v: e[u]) {
        if (v == fa) continue;
        del(v, u);
    }
}

void dfs1(int u, int fa, int op) {
    for (int v: e[u]) {
        if (v == fa || v == son[u]) continue;
        dfs1(v, u, 0);
    }
    if (son[u])dfs1(son[u], u, 1);
    add(u, fa, son[u]);
    ans[u] = val;
    if (!op) del(u, fa), mx = val = 0;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
