//
// Created by 27682 on 2025/7/1.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

constexpr int N = 1e5 + 10;

int n;
vi e[N], have;

struct Node {
    int st, ed;
    int sex, val;
} a[N];

int id[N * 2], tick = 0;
int f[N][22], dep[N];

inline void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1, f[u][0] = fa;
    for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];

    a[u].st = ++tick;
    id[tick] = u;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    a[u].ed = ++tick;
    id[tick] = u;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; ~i; i--) if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    if (u == v) return u;
    for (int i = 19; ~i; i--) if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return f[u][0];
}

int q, len;

struct Query {
    int l, r, s, id;
};

vector<Query> queries;

int get(int i) {
    return i / len;
}

bool cmp(const Query &a, const Query &b) {
    int la = get(a.l), lb = get(b.l);
    if (la != lb) return la < lb;
    return la & 1 ? a.r < b.r : a.r > b.r;
}

ll ans[N], res = 0;

int num[N][2], tag[N];

inline void add(int pos) {
    res += num[a[pos].val][a[pos].sex ^ 1];
    ++num[a[pos].val][a[pos].sex];
}

inline void del(int pos) {
    res -= num[a[pos].val][a[pos].sex ^ 1];
    --num[a[pos].val][a[pos].sex];
}

inline void move(int pos) {
    tag[id[pos]] ^= 1;
    tag[id[pos]] ? add(id[pos]) : del(id[pos]);
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].sex;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        have.push_back(a[i].val);
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    for (int i = 1; i <= n; i++) a[i].val = lower_bound(have.begin(), have.end(), a[i].val) - have.begin() + 1;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cin >> q;
    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        if (a[x].st > a[y].st) swap(x, y);
        if (a[x].ed > a[y].ed) queries.push_back({a[x].st, a[y].st, 0, i});
        else queries.push_back({a[x].ed, a[y].st, lca(x, y), i});
    }
    len = sqrt(n) + 1;
    sort(queries.begin(), queries.end(), cmp);
    int l = 0, r = 0;
    for (auto [lx, rx, op, id]: queries) {
        while (r < rx) move(++r);
        while (l > lx) move(--l);
        while (r > rx) move(r--);
        while (l < lx) move(l++);
        ans[id] = res;
        if (op) ans[id] += num[a[op].val][a[op].sex ^ 1];
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
