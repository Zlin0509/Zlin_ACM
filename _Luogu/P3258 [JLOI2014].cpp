#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n, a[N], sum[N];
vector<int> e[N << 1];
int dep[N], fa[N][22];
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
inline void Get(int u, int f)
{
    for (auto v : e[u])
    {
        if (v != f)
        {
            Get(v, u);
            sum[u] += sum[v];
        }
    }
}
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 2, f; i <= n; i++)
    {
        f = lca(a[i], a[i - 1]);
        ++sum[a[i]];
        ++sum[a[i - 1]];
        --sum[f];
        --sum[fa[f][0]];
    }
    Get(1, 0);
    for (int i = 2; i <= n; i++)
        sum[a[i]]--;
    for (int i = 1; i <= n; i++)
        cout << sum[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Zlin();
    return 0;
}