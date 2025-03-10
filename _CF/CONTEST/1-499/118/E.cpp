//
// Created by Zlin on 2025/1/19.
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

int n, m;
vector<unordered_set<int>> e;
int tot = 0;
vi dfn, low, parent;
vector<bool> vis;
set<pii> bridges;

inline void tarjan(int u)
{
    vis[u] = true;
    dfn[u] = low[u] = ++tot;
    for (int v : e[u])
    {
        if (!vis[v])
        {
            parent[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                bridges.insert({min(u, v), max(u, v)});
        }
        else if (v != parent[u])
            low[u] = min(low[u], dfn[v]);
    }
}

vector<pii> ans;

inline void dfs(int u)
{
    vis[u] = true;
    while (!e[u].empty())
    {
        int v = *e[u].begin();
        e[u].erase(e[u].begin());
        ans.push_back({u, v});
        e[v].erase(e[v].find(u));
        dfs(v);
    }
}

inline void Zlin()
{
    cin >> n >> m;
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    vis.assign(n + 1, false);
    e.assign(n + 1, unordered_set<int>());
    parent.assign(n + 1, 0);
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }
    tarjan(1);
    if (!bridges.empty())
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            cout << 0 << '\n';
            return;
        }
    dfs(1);
    for (auto it : ans)
        cout << it.first << " " << it.second << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
