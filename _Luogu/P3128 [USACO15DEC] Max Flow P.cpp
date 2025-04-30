#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n, k, ans = 0;
vector<int> e[N];
int dep[N], fa[N][22], sum[N];
inline void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : e[u])
        if (v != f)
            dfs(v, u);
}
inline int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i]; // 让u，v处于同一层
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i]; // 返回祖先的下一层
    return fa[u][0];
}
inline void Get(int u, int fa)
{
    for (auto v : e[u])
    {
        if (v != fa)
        {
            Get(v, u);
            sum[u] += sum[v];
        }
    }
    ans = max(ans, sum[u]);
}
inline void Zlin()
{
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1, u, v, f; i <= k; i++)
    {
        cin >> u >> v;
        f = lca(u, v);
        sum[u]++;
        sum[v]++;
        sum[f]--;
        sum[fa[f][0]]--;
    }
    Get(1, 0);
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}