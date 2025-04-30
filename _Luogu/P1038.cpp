#include "bits/stdc++.h"
using namespace std;
const int N = 110000;
vector<int> val(N), c(N), tp;
int n, p;
int tot = 0, head[N], d[N], check[N];
struct edge
{
    int to, next, val;
} e[N];
inline void add(int u, int v, int val)
{
    ++d[v];
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    e[tot].val = val;
    head[u] = tot;
}
inline void toposort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (check[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to;
            --d[v];
            if (c[u] > 0)
                c[v] += c[u] * e[i].val;
            if (!d[v])
                q.push(v);
        }
    }
}
inline void Zlin()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> val[i];
        if (c[i])
            check[i] = 1;
        else
            c[i] -= val[i];
    }
    for (int i = 1, u, v, val; i <= p; i++)
        cin >> u >> v >> val, add(u, v, val);
    toposort();
    bool ss = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!head[i] && c[i] > 0)
            cout << i << ' ' << c[i] << '\n', ss = 0;
    }
    if (ss)
        cout << "NULL";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}