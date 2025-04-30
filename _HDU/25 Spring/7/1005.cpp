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

constexpr int N = 4e5 + 10;
int cnt = 0, comp_count = 0;
vi e[N], tree[N];
int dfn[N], low[N], fa[N], compID[N], num[N];
bool vis[N];
set<pii> bridges;

int n, m;
ll val[N], a[N];

inline void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    for (int v: e[u]) {
        if (!vis[v]) {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) bridges.insert({min(u, v), max(u, v)});
        } else if (v != fa[u]) low[u] = min(low[u], dfn[v]);
    }
}

inline void dfs(int u, int ID) {
    compID[u] = ID;
    for (int v: e[u])
        if (compID[v] == -1 && bridges.find({min(u, v), max(u, v)}) == bridges.end())
            dfs(v, ID);
}

inline void build() {
    for (int i = 1; i <= n; i++)
        if (compID[i] == -1)
            dfs(i, ++comp_count);
    for (auto it: bridges) {
        int u = compID[it.first], v = compID[it.second];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}

ll ans, now, res;
int lx, rx, ff[N];
vi ee[N];

inline int find(int u) {
    return ff[u] == u ? u : ff[u] = find(ff[u]);
}

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    ff[fy] = fx;
    val[fx] += val[fy];
}

inline bool dfs1(int u, int fa) {
    bool check = num[u] >= 3;
    for (int v: tree[u]) {
        if (v == fa || find(v) == find(u)) continue;
        if (dfs1(v, u)) {
            check = true;
            merge(u, v);
        }
    }
    return check;
}

inline void add(int u, int fa) {
    for (int v: tree[u]) {
        if (v == fa) continue;
        if (find(u) != find(v)) {
            ee[find(u)].push_back(find(v));
            ee[find(v)].push_back(find(u));
        }
        add(v, u);
    }
}

int s;

inline void build2() {
    s = 0;
    for (int i = 1; i <= comp_count; i++) {
        if (num[i] >= 3) {
            dfs1(i, 0);
            s = find(i);
            break;
        }
    }
    add(find(1), 0);
}

inline ll dfs3(int u, int fa, ll len) {
    ll l = 0, r = 0;
    for (int v: ee[u]) {
        if (v == fa) continue;
        ll res = dfs3(v, u, len + val[v]);
        if (res > l) {
            r = l, l = res;
        } else if (res > r) {
            r = res;
        }
    }
    ans = max(ans, l + r + len);
    return l + val[u];
}

inline ll dfs2(int u, int fa) {
    ll l = 0, r = 0;
    for (int v: ee[u]) {
        if (v == fa) continue;
        ll res = dfs2(v, u);
        if (res > l) {
            r = l, l = res;
        } else if (res > r) {
            r = res;
        }
    }
    ans = max(ans, l + r + val[u]);
    return l + val[u];
}

inline void Zlin() {
    cin >> n >> m;

    comp_count = 0;
    cnt = 0;
    bridges.clear();
    for (int i = 1; i <= n; i++) {
        fa[i] = 0;
        val[i] = 0;
        dfn[i] = low[i] = vis[i] = 0;
        compID[i] = -1;
        e[i].clear();
        ee[i].clear();
        tree[i].clear();
        num[i] = 0;
        ff[i] = i;
    }

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    build();
    for (int i = 1; i <= n; i++) val[compID[i]] += a[i], num[compID[i]]++;
    build2();
    ans = 0;
    if (s) dfs3(s, 0, val[s]);
    else dfs2(find(1), 0);
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int size(256 << 20); //256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char *) malloc(size) + size));
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    exit(0);
}
