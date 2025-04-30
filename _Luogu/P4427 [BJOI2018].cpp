#include "bits/stdc++.h"
using namespace std;
using ull = unsigned long long;
const ull MOD = 998244353;
const int N = 3e5 + 5;
ull n, m, dep[N], fa[N][22];
ull sum[N][55];
vector<int> e[N];
inline ull quick_pow(ull a, int n)
{
    ull res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
inline void dfs(int u, int f)
{
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = 1; i <= 50; i++)
        sum[u][i] = (sum[f][i] + quick_pow(dep[u] - 1, i)) % MOD;
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
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    int i, j, k;
    ull ans;
    while (m--)
    {
        cin >> i >> j >> k;
        int f = lca(i, j);
        ans = (sum[i][k] + sum[j][k] - sum[f][k] - sum[fa[f][0]][k] + MOD * 10) % MOD;
        cout << ans << '\n';
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