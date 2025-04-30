#include "bits/stdc++.h"
using namespace std;

using ll = long long;
int n, ans[100005], xx = 0;
int d[100005], val[100005];
int tot = 0, head[100005];
struct edge
{
    int to, next;
} e[100005];

inline void add(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

inline void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        --d[v];
        ans[v] = max(ans[v], ans[u] + val[v]);
        if (!d[v])
            dfs(v, u);
    }
}

void Zlin()
{
    cin >> n;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x;
        cin >> val[x];
        cin >> y;
        while (y)
        {
            add(y, x);
            ++d[x];
            cin >> y;
        }
        ans[x] = val[x];
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            dfs(i, i);
    for (int i = 1; i <= n; i++)
        xx = max(xx, ans[i]);
    cout << xx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}