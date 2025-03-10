//
// Created by Zlin on 2025/1/18.
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

constexpr int N = 2e5 + 10;
int n, m;
int cnt = 0, comp_count = 0;
vector<vi> e, tree, have;
vi dfn, low, fa, f, compID, in;
vector<pii> ans;
vector<bool> vis;
set<pii> bridges;

inline void tarjan(int u)
{
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    for (int v : e[u])
    {
        if (!vis[v])
        {
            fa[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                bridges.insert({min(u, v), max(u, v)});
        }
        else if (v != fa[u]) low[u] = min(low[u], dfn[v]);
    }
}

inline void dfs(int u, int ID)
{
    compID[u] = ID;
    for (int v : e[u])
        if (compID[v] == -1 && bridges.find({min(u, v), max(u, v)}) == bridges.end())
            dfs(v, ID);
}

inline void build(int n)
{
    compID.assign(n + 1, -1);

    for (int i = 1; i <= n; i++)
        if (compID[i] == -1)
            dfs(i, ++comp_count);
    in.assign(n + 1, 0);
    have.assign(comp_count + 1, vi());
    for (auto it : bridges)
    {
        int u = compID[it.first], v = compID[it.second];
        ++in[u], ++in[v];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        have[compID[i]].push_back(i);
}

inline int find(int u)
{
    return f[u] == u ? u : f[u];
}

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fx] = fy;
}

inline void xxx(int n, vector<vi> e)
{
    f.assign(n + 1, 0);
    queue<int> q;
    vi vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        if (in[i] == 1)
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (int v : e[u])
        {
            if (vis[v]) continue;
            f[u] = v;
            if (in[v] <= 2)
                q.push(v);
        }
    }
}

inline void solve(int n)
{
    vi now;
    for (int i = 1; i <= n; i++)
        if (in[i] <= 1)
            now.push_back(i);
    while (1)
    {
        int tag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!tag) tag = find(i);
            else if (tag != find(i))
            {
                tag = -1;
                break;
            }
        }
        if (tag == -1)
            break;

        int x = now.back();
        now.pop_back();
        for (auto it : now)
            if (find(x) != find(it))
            {
                ans.push_back({x, it});
                merge(x, it);
                break;
            }
    }
    while (now.size() > 1)
    {
        int x = now.back();
        now.pop_back();
        int y = now.back();
        now.pop_back();
        ans.push_back({x, y});
    }
    if (now.size() == 1)
    {
    }
}

inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 2)
    {
        cout << -1 << '\n';
        return;
    }
    build(n);
    xxx(comp_count, tree);
    solve(comp_count);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
