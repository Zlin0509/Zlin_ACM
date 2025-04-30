#include <bits/stdc++.h>
using namespace std;

int n, m, s, cnt = 0;
int vis[10010]{}, head[10010]{};
int dis[10010]{};

struct edge
{
    int to, next, dis;
} e[500010]{};

inline void add_edge(int u, int v, int dis)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = dis;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void spfa()
{
    dis[s] = 0;
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
            int y = e[i].to, d = e[i].dis;
            if (dis[y] > dis[x] + d)
            {
                dis[y] = dis[x] + d;
                if (!vis[y])
                    vis[y] = 1, q.push(y);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 10010; i++)
        dis[i] = 2147483647;

    cin >> n >> m >> s;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    spfa();

    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
}