//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 5;
constexpr int inf = 1e8;

int n, m;
int in[N], f[N], siz[N], vis[N];
vi e[N];

inline int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
    siz[fx] += siz[fy];
}

void init() {
    for (int i = 1; i <= n; i++) {
        in[i] = vis[i] = 0;
        f[i] = i;
        siz[i] = 1;
        e[i].clear();
    }
}

void dfs(int u) {
    for (int v: e[u]) {
        if (in[v] != 2 || find(u) == find(v)) continue;
        merge(u, v);
        dfs(v);
    }
}

inline void Zlin() {
    cin >> n >> m;
    init();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        merge(u, v);
        ++in[u], ++in[v];
    }
    int k = sqrt(n);
    if (k * k != n || siz[find(1)] != n) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        f[i] = i, siz[i] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 2) continue;
        if (in[i] == 4) {
            ++cnt;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if (cnt != k) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 4)
            dfs(i);
    for (int i = 1; i <= n; i++) {
        if (siz[find(i)] != k) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
