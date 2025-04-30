//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef int i32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<i32> vi;
typedef vector<i64> vll;
typedef pair<i32, i32> pii;
typedef pair<i64, i64> pll;

constexpr int N = 1e6 + 10;

int n;
int len[N], son[N];
vi e[N];

void dfs(int u, int fa) {
    len[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (len[v] + 1 > len[u])
            len[u] = len[v] + 1, son[u] = v;
    }
}

int ans[N];
int pool[N];
int *f[N], *tag = pool;

void dfs1(int u, int fa) {
    f[u][0] = 1;
    if (son[u]) {
        f[son[u]] = f[u] + 1;
        dfs1(son[u], u);
        ans[u] = ans[son[u]] + 1;
    }
    for (int v: e[u]) {
        if (v == fa || v == son[u]) continue;
        f[v] = tag, tag += len[v];
        dfs1(v, u);
        for (int i = 1; i <= len[v]; i++) {
            f[u][i] += f[v][i - 1];
            if (f[u][i] > f[u][ans[u]] || (f[u][i] == f[u][ans[u]] && i < ans[u]))
                ans[u] = i;
        }
    }
    if (f[u][ans[u]] == 1) ans[u] = 0;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    f[1] = tag, tag += len[1];
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
