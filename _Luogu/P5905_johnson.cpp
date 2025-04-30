#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int head[3010]{};
int vis[3010]{};
int num[3010]{}; // 邻接矩阵;
long long dis[3010]{}, h[3010]{};
long long ans = 0;
const long long INF = 1e9;

struct edge
{
    int to, next;
    long long w;
} e[12010]{};

struct node
{
    long long dis;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};

inline void add_edge(int u, int v, int w)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline bool spfa(int s)
{
    for (int i = 1; i <= n; i++)
        h[i] = 63, vis[i] = 0;
    h[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    int x;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to, d = e[i].w;
            if (h[y] > h[x] + d)
            {
                h[y] = h[x] + d;
                if (!vis[y])
                {
                    ++num[y];
                    if (num[y] > n)
                        return false;
                    vis[y] = 1, q.push(y);
                }
            }
        }
    }
    return true;
}

priority_queue<node> q;

inline void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF, vis[i] = 0;
    q.push({0, s});
    dis[s] = 0;
    int u;
    while (!q.empty())
    {
        u = q.top().pos;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int y = e[i].to;
            long long d = e[i].w;
            if (dis[y] > dis[u] + d)
            {
                dis[y] = dis[u] + d;
                if (!vis[y])
                    q.push({dis[y], y});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
        add_edge(0, i, 0);
    if (!spfa(0))
    {
        cout << "-1" << '\n';
        return 0;
    }

    for (int j = 1; j <= n; j++)
        for (int i = head[j]; i; i = e[i].next)
            e[i].w = e[i].w + h[j] - h[e[i].to];

    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        dijkstra(i);
        for (int j = 1; j <= n; j++)
            if (dis[j] == INF)
                ans += j * INF;
            else
                ans += j * (dis[j] - h[i] + h[j]);
        cout << ans << '\n';
    }
}