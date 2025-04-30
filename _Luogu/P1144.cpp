#include <bits/stdc++.h>
using namespace std;

const int Mod = 100003;
const int INF = 1e9;

struct edge
{
    int to, next;
} e[4000010]{};
int num[1000010]{};
int head[1000010]{}, dis[1000010]{}, vis[1000010]{};
int cnt = 0;
int n, m;

inline void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

struct node
{
    int dis, pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};

priority_queue<node> q;

inline void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF, vis[i] = 0;
    dis[s] = 0;
    num[s] = 1;
    q.push({0, s});
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
            int v = e[i].to;
            if (dis[v] > dis[u] + 1)
            {
                num[v] = 0;
                dis[v] = dis[u] + 1;
                if (!vis[v])
                    q.push({dis[v], v});
            }
            if (dis[v] == dis[u] + 1)
                num[v] += num[u], num[v] %= Mod;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << num[i] << '\n';
}