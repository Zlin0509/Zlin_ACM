//
// Created by Zlin on 2024/10/29.
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

const int N = 500010;

struct edge {
    int v, nxt;
} e[N << 1];
int dfn[N], low[N], idx = 1, head[N << 1], id, stk[N], top, cnt, scc[N], sz[N];
int n, m, k;

inline void add(int x, int y) {
    e[++idx].v = y;
    e[idx].nxt = head[x];
    head[x] = idx;
}

inline void tarjan(int x, int from) {
    dfn[x] = low[x] = ++id;
    stk[++top] = x;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].v;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
        } else if (i != (from ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        cnt++;
        int y;
        do {
            y = stk[top--];
            sz[cnt]++;
            scc[y] = cnt;
        } while (y != x);
    }
}

int vis[N], szid = 0, tsz[N];
vector<int> SZ[N], E[N];
bitset<50010> f[2][2];

int dfs1(int u) {
    int siz = sz[u];
    vis[u] = 1;
    for (int v: E[u]) {
        if (vis[v]) continue;
        siz += dfs1(v);
    }
    SZ[szid].push_back(siz);
    return siz;
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) head[i] = 0;
    idx = 1, id = top = cnt = 0;
    szid = 0;
    for (int i = 1; i <= n; i++)
        dfn[i] = low[i] = scc[i] = sz[i] = 0, E[i].clear(), SZ[i].clear(), tsz[i] = 0, vis[i] = 0;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i, 0);
    }
    if (cnt == 1) {
        cout << "-1" << '\n';
        return;
    }
    for (int u = 1; u <= n; u++) {
        for (int i = head[u]; i; i = e[i].nxt) {
            if (scc[e[i].v] != scc[u])
                E[scc[e[i].v]].push_back(scc[u]);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (!vis[i]) {
            SZ[++szid].clear();
            int tot = dfs1(i), siz = SZ[szid].size();
            tsz[szid] = tot;
            for (int j = 0; j < siz; j++)
                SZ[szid].push_back(tot - SZ[szid][j]);
        }
    }
    f[0][0].reset(), f[0][1].reset();
    f[1][0].reset(), f[1][1].reset();
    f[0][0][0] = f[1][0][0] = true;
    for (int i = 1; i <= szid; i++) {
        f[0][i & 1] = (f[0][i & 1 ^ 1] | (f[0][i & 1 ^ 1] << tsz[i]));
        f[1][i & 1] = (f[1][i & 1 ^ 1] | (f[1][i & 1 ^ 1] << tsz[i]));
        for (int v: SZ[i]) f[0][i & 1] |= (f[1][i & 1 ^ 1] << v);
    }
    ll ans = 1e18;
    for (int i = 0; i <= n / 2; i++)
        if (f[0][szid & 1][i] || f[1][szid & 1][i])
            ans = min(ans, 1ll * (szid - 1) * k + 1ll * i * i + 1ll * (n - i) * (n - i));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}

