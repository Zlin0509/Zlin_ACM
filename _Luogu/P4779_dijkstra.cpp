#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int dis[100010]{}, head[100010]{};
int vis[100010]{};
int cnt = 0;

struct edge
{
    int to, next, w;
} a[200010]{};

struct node
{
    int dis;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
priority_queue<node> q;

inline void add_edge(int u, int v, int w)
{
    ++cnt;
    a[cnt].to = v;
    a[cnt].w = w;
    a[cnt].next = head[u];
    head[u] = cnt;
}

inline void dijkstra()
{
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        int x = u.pos;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = a[i].next)
        {
            int y = a[i].to;
            if (dis[y] > dis[x] + a[i].w)
            {
                dis[y] = dis[x] + a[i].w;
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

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        dis[i] = 0x7fffffff;

    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}