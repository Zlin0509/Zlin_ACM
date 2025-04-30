#include "bits/stdc++.h"
using namespace std;

const int MOD = 10007;
const int N = 2e5 + 5;
int tot = 0, head[N << 1];
struct edge
{
    int to, next;
} e[N << 1];
inline void add(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int n, val[N], ans = 0, sum = 0;
inline void dfs(int u, int fa, int ffa)
{
    int max1 = 0, max2 = 0, s1 = 0, s2 = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != fa)
        {
            s1 = (s1 + val[v]) % MOD;
            s2 = (s2 + val[v] * val[v]) % MOD;
            if (val[v] > max1)
                max2 = max1, max1 = val[v];
            else if (val[v] > max2)
                max2 = val[v];
            dfs(v, u, fa);
        }
    }
    ans = max(ans, max(max1 * max2, val[u] * val[ffa]));
    sum = (sum + (s1 * s1 - s2 + MOD) % MOD + val[u] * val[ffa] * 2 % MOD) % MOD;
}
inline void Zlin()
{
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    dfs(1, 0, 0);
    cout << ans << ' ' << sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}