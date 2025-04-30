#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 10, INF = 1e6;
int tot = 0, head[N];
struct edge
{
    int to, val, next;
} e[N];
inline void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}
int n, m, mm, dis[N], num[N], used[N];
inline bool spfa(int s)
{
    queue<int> q;
    memset(dis, INF, sizeof dis);
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        used[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].to, val = e[i].val;
            if (dis[v] > dis[u] + val)
            {
                dis[v] = dis[u] + val;
                if (!used[v])
                {
                    ++num[v];
                    if (num[v] > N)
                        return false;
                    used[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, u, v, val; i <= m; i++)
    {
        cin >> u >> v >> val;
        add(v, u, val);
    }
    for (int i = 1; i <= n; i++)
        add(n + 1, i, 0);
    bool check = spfa(n + 1);
    if (!check)
    {
        cout << "NO SOLUTION";
        return;
    }
    for (int i = 1; i <= n; i++)
        mm = min(mm, dis[i]);
    for (int i = 1; i <= n; i++)
        cout << dis[i] - mm << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}