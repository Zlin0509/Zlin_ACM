//
// Created by 27682 on 2025/7/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 10;

int n, m;
int w[N];

struct Tree {
    int l, r, val, tag;
} t[N << 2];

// 建树
void build(int i, int l, int r) {
    if (l == r) {
        t[i].l = l, t[i].r = r;
        t[i].val = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    t[i].l = l, t[i].r = r;
    t[i].val = max(t[i << 1].val, t[i << 1 | 1].val);
}

//更新懒标记
void pushdown(int i) {
    if (!t[i].tag) return;
    t[i].val += t[i].tag * (t[i].r - t[i].l + 1);
    if (t[i].l != t[i].r) {
        t[i << 1].tag += t[i].tag;
        t[i << 1 | 1].tag += t[i].tag;
    }
    t[i].tag = 0;
}

//区间修改
void modify(int i, int l, int r, int z) {
    if (t[i].l > r || t[i].r < l) return;
    pushdown(i);
    if (t[i].l >= l && t[i].r <= r) {
        t[i].tag += z;
        pushdown(i);
        return;
    }
    modify(i << 1, l, r, z);
    modify(i << 1 | 1, l, r, z);
    t[i].val = max(t[i << 1].val, t[i << 1 | 1].val);
}

//区间查询
int query(int i, int l, int r) {
    if (t[i].l > r || t[i].r < l) return 0;
    pushdown(i);
    if (t[i].l >= l && t[i].r <= r) return t[i].val;
    return query(i << 1, l, r) + query(i << 1 | 1, l, r);
}

struct Node {
    int dep, fa, son, siz, val, top, dfn;
} tn[N];

struct edge {
    int to, nxt;
} e[N];

int tot = 0, head[N];

void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

// 预处理，找出树的所有重儿子和重链
void dfs1(int u, int f) {
    tn[u].fa = f;
    tn[u].dep = tn[f].dep + 1;
    tn[u].siz = 1;
    int tmp = -1; // 临时变量，用来存储结点u的重儿子
    for (int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if (v == f) continue;
        dfs1(v, u);
        tn[u].siz += tn[v].siz;
        if (tn[v].siz > tmp) {
            // 如果结点v.siz更大，更新u的重儿子为v
            tn[u].son = v;
            tmp = tn[v].siz;
        }
    }
}

int tim = 0; // w用来存储对应dfn序下的树上结点val，tim为dfn计数器

void dfs2(int u, int top) {
    tn[u].top = top;
    tn[u].dfn = ++tim;
    w[tim] = tn[u].val;
    if (!tn[u].son) return; // 如果没有重儿子，说明为叶节点
    dfs2(tn[u].son, top); // 向下传递重链，重链的top一样
    for (int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if (v == tn[u].fa || v == tn[u].son) continue;
        dfs2(v, v); // 轻链的top为他自身
    }
}

// 修改结点u和他的子树，因为dfn连续，所以映射在线段树上是区间修改
void change_1(int u, int z) {
    modify(1, tn[u].dfn, tn[u].dfn + tn[u].siz - 1, z);
}

// 同理
int query_1(int u) {
    return query(1, tn[u].dfn, tn[u].dfn + tn[u].siz - 1);
}

// 修改一条链上的所有值，重链上的dfn都是连续的
void change_2(int x, int y, int z) {
    while (tn[x].top != tn[y].top) {
        // 如果他两不在同一条重链上，找出top深度大的，往上翻
        if (tn[tn[x].top].dep < tn[tn[y].top].dep) swap(x, y);
        modify(1, tn[tn[x].top].dfn, tn[x].dfn, z);
        x = tn[tn[x].top].fa;
    }
    if (tn[x].dep > tn[y].dep) swap(x, y);
    modify(1, tn[x].dfn, tn[y].dfn, z);
}

// 查询一条链上的所有值，同理
int query_2(int x, int y) {
    int res = 0;
    while (tn[x].top != tn[y].top) {
        // 如果他两不在同一条重链上，找出top深度大的，往上翻
        if (tn[tn[x].top].dep < tn[tn[y].top].dep) swap(x, y);
        res += query(1, tn[tn[x].top].dfn, tn[x].dfn);
        x = tn[tn[x].top].fa;
    }
    if (tn[x].dep > tn[y].dep) swap(x, y);
    res += query(1, tn[x].dfn, tn[y].dfn);
    return res;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        tn[i] = {0, 0, 0, 0, 0, 0, 0};
        cin >> tn[i].val;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
