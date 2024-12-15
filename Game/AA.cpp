//
// Created by Zlin on 2024/12/1.
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

const int N = 2e5;

int n, m;
vi e[N];

struct node {
    int val, id;

    bool operator<(const node &x) const {
        return val < x.val;
    }
} a[N];

int in[N], dep[N];
int dfn[N], low[N], tot = 0;
int stk[N], instk[N], top = 0;
int scc[N], cnt = 0;

inline void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y;
        ++cnt;
        do {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
        } while (y != x);
    }
}

vi ans;

struct node2 {
    int dep, id;

    bool operator<(const node2 &x) const {
        return dep > x.dep;
    }
};

void bfs(int s) {
    priority_queue<node2> q;
    dep[s] = 1;
    q.push({dep[s], s});
    while (!q.empty()) {
        node2 x = q.top();
        int u = x.id, val = x.dep;
        q.pop();
        for (int v: e[u]) {
            --in[v];
            if (val + 1 <= dep[v] || in[v]) continue;
            dep[v] = val + 1;
            q.push({dep[v], v});
        }
    }
}

int vis[N], used[N];

void dfs(int u) {
    ans.push_back(u);
    used[u] = 1;
    for (int v: e[u])
        if (dep[v] == dep[u] + 1)
            dfs(v);
}


inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, tag; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[j].val, a[j].id = j;
        sort(a + 1, a + 1 + m);
        vector<node> q, qq;
        tag = 1;
        while (a[tag].val == -1) ++tag;
        if (tag > m) continue;
        q.push_back(a[tag]);
        for (int j = tag + 1; j <= m; j++) {
            if (q.front().val == a[j].val) {
                q.push_back(a[j]);
            } else if (qq.empty() || qq.front().val == a[j].val) {
                qq.push_back(a[j]);
            } else {
                for (auto x: q)
                    for (auto y: qq)
                        e[x.id].push_back(y.id);
                q = qq;
                qq.clear();
                qq.push_back(a[j]);
            }
        }
        for (auto x: q)
            for (auto y: qq)
                e[x.id].push_back(y.id);
    }
    for (int i = 1; i <= m; i++) {
        sort(e[i].begin(), e[i].end());
        e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    }
//    for (int i = 1; i <= m; i++) for (auto it: e[i]) cout << i << ' ' << it << '\n';
    for (int i = 1; i <= m; i++)
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (int v: e[u]) {
                    ++in[v];
                    if (!vis[v]) q.push(v);
                }
            }
        }
    for (int i = 1; i <= m; i++) if (!dfn[i]) tarjan(i);
    if (cnt != m) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= m; i++)
        if (!in[i] && !used[i]) {
            bfs(i);
            dfs(i);
        }
    for (auto it: ans) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}