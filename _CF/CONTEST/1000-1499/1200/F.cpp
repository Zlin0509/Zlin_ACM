//
// Created by 27682 on 2025/6/23.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 1010;
constexpr int all = 2520;

// all = 2520

int n, k[N], m[N], q;
vi e[N * all], g[N * all];

int vis[N * all];

inline void dfs(int u, int val) {
    vis[u * all + val] = 1;
    for (int i = 0; i < m[u]; i++) {
        int v = e[u][i], vx = (val + k[v]) % all;
        if ((val % m[u] + m[u]) % m[u] != i) continue;
        g[u * all + val].push_back(v * all + vx);
        if (!vis[v * all + vx]) dfs(v, vx);
    }
}

int dfn[N * all], low[N * all], tot = 0;
int stk[N * all], instk[N * all], top = 0;
int scc[N * all], num = 0;
set<int> siz[N * all];

inline void tarjan(int u) {
    if (u / all == 2) {
    }
    dfn[u] = low[u] = ++tot;
    stk[++top] = u, instk[u] = 1;
    bool spe = false;
    for (int v: g[u]) {
        if (v == u) spe = true;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instk[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        int v;
        ++num;
        int cnt = 0;
        do {
            ++cnt;
            v = stk[top--];
            instk[v] = 0;
            scc[v] = num;
            siz[num].insert(v / all);
        } while (u != v);
        if (cnt == 1 && !spe) siz[num].erase(siz[num].begin());
    }
}

int in[N * all];

inline void build_new() {
    for (int i = all; i < (n + 1) * all; i++) if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= num; i++) e[i].clear();
    for (int i = all; i < (n + 1) * all; i++) for (int j: g[i]) if (scc[i] != scc[j]) e[scc[j]].push_back(scc[i]);
    for (int i = 1; i <= num; i++) {
        sort(e[i].begin(), e[i].end());
        e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    }
    for (int i = 1; i <= num; i++) for (int j: e[i]) ++in[j];
}

inline void topo() {
    queue<int> q;
    for (int i = 1; i <= num; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            for (int it: siz[u]) siz[v].insert(it);
            if (!--in[v]) q.push(v);
        }
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] = (k[i] % all + all) % all;
    }
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        e[i].assign(m[i], 0);
        for (int &it: e[i]) cin >> it;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < all; j++) {
            if (!vis[i * all + j]) {
                dfs(i, j);
            }
        }
    }
    build_new();
    topo();
    cin >> q;
    while (q--) {
        int x, c;
        cin >> x >> c;
        cout << siz[scc[x * all + ((c + k[x]) % all + all) % all]].size() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
