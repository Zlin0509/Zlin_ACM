#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N];
int n, q, dep[N], fa[N][22];
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
inline void Zlin()
{
    cin >> n >> q;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1, a, b, c, d; i <= q; i++)
    {
        cin >> a >> b >> c >> d;
        int x = lca(a, b), y = lca(c, d);
        bool check = 0;
        if (dep[x] >= dep[y] && (lca(x, c) == x || lca(x, d) == x))
            check = 1;
        if (dep[y] >= dep[x] && (lca(y, a) == y || lca(y, b) == y))
            check = 1;
        cout << (check ? "Y" : "N") << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}