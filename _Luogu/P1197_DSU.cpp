#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int f[400010]{}, ans[400010]{}, hit[400010]{};
bool check[400010]{};
struct node
{
    int to, next, from;
} e[400010]{};
int tot = 0, head[400010]{};

inline void add_edge(int x, int y)
{
    ++tot;
    e[tot].from = x;
    e[tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
}

inline int Get(int x)
{
    if (x == f[x])
        return x;
    return f[x] = Get(f[x]);
}

inline void Ss(int x, int y)
{
    int x1 = Get(x), y1 = Get(y);
    if (x1 != y1)
        --cnt, f[x1] = y1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        f[i] = i, check[i] = false;

    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    int k;
    cin >> k;
    cnt = n - k;
    for (int i = 1, x; i <= k; i++)
    {
        cin >> x;
        check[x] = true;
        hit[i] = x;
    }
    for (int i = 1; i <= tot; i++)
    {
        if (!check[e[i].from] && !check[e[i].to])
            Ss(e[i].from, e[i].to);
    }
    ans[k + 1] = cnt;
    for (int i = k, u; i >= 1; i--)
    {
        u = hit[i];
        ++cnt;
        check[u] = false;
        for (int j = head[u]; j; j = e[j].next)
            if (!check[e[j].to])
                Ss(u, e[j].to);
        ans[i] = cnt;
    }
    for (int i = 1; i <= k + 1; i++)
        cout << ans[i] << '\n';
}