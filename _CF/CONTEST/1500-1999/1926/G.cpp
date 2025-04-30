//
// Created by Zlin on 2024/10/30.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
const int inf = 1e9;

struct edge {
    int v, nxt;
} e[N << 1];
int head[N], tot;

inline void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

int n, f[N][2];
string s;

inline void dfs(int u, int fa) {
    f[u][0] = f[u][1] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
        f[u][0] += min(f[v][0], f[v][1] + 1);
        f[u][1] += min(f[v][1], f[v][0] + 1);
    }
    if (s[u] == 'P') f[u][0] = inf;
    if (s[u] == 'S') f[u][1] = inf;
}

inline void Zlin() {
    cin >> n;
    tot = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 2, v; i <= n; i++) {
        cin >> v;
        add(i, v);
        add(v, i);
    }
    cin >> s;
    s = ' ' + s;
    dfs(1, 0);
    cout << min(f[1][0], f[1][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}