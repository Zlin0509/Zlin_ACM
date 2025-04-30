//
// Created by 27682 on 2025/4/22.
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

int n, m, tagtt, f[N], in[N];
vi e[N], ee[N];

struct line {
    int u, v, w;
};

vector<line> line;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
    --tagtt;
}

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], num;

inline void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u, instk[u] = 1;
    for (int v: e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instk[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        int v;
        ++num;
        do {
            v = stk[top--];
            instk[v] = 0;
            scc[v] = num;
        } while (u != v);
    }
}

inline void build() {
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int u = 1; u <= n; u++) {
        for (int v: e[u]) {
            if (scc[u] != scc[v]) {
                ee[scc[u]].push_back(scc[v]);
            }
        }
    }
    for (int i = 1; i <= num; i++) {
        sort(ee[i].begin(), ee[i].end());
        ee[i].erase(unique(ee[i].begin(), ee[i].end()), ee[i].end());
    }
    for (int i = 1; i <= num; i++) {
        for (int it: ee[i]) {
            ++in[it];
        }
    }
}

inline bool check(int dif) {
    tot = top = num = 0;
    for (int i = 1; i <= n; i++) {
        in[i] = 0;
        dfn[i] = low[i] = stk[i] = instk[i] = scc[i] = 0;
        e[i].clear();
        ee[i].clear();
    }
    for (auto [u, v, w]: line) {
        e[u].push_back(v);
        if (w <= dif) e[v].push_back(u);
    }
    build();
    int res = 0;
    for (int i = 1; i <= num; i++) res += in[i] == 0;
    return res <= 1;
}

inline void Zlin() {
    cin >> n >> m;
    line.clear();
    tagtt = n;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        line.push_back({u, v, w});
        merge(u, v);
    }
    if (tagtt != 1) {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
