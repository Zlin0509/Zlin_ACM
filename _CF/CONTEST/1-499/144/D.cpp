//
// Created by Zlin on 2025/1/19.
//

#include "bits/stdc++.h"
#define endl "\n"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 1E5 + 10;
constexpr int INF = 1e9;

int n, m, s, l;
vi dis;
vector<bool> vis;

struct edge
{
    int u, v, w;
};

vector<edge> ee;

struct Edge
{
    int to, nxt, val;
} e[N << 1];

int tot = 0, head[N];

inline void add(int u, int v, int w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
}

inline void dij()
{
    vis.assign(n + 1, false);
    dis.assign(n + 1, INF);
    priority_queue<pii> q;
    dis[s] = 0;
    q.push({-dis[s], s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                    q.push({-dis[v], v});
            }
        }
    }
}

inline void Zlin()
{
    cin >> n >> m >> s;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        ee.push_back({u, v, w});
        add(u, v, w);
        add(v, u, w);
    }
    cin >> l;
    dij();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dis[i] == l)
            ++ans;
    for (auto [u,v,w] : ee)
    {
        if (min(dis[u], dis[v]) >= l)
            continue;
        int x = dis[u] + dis[v] + w;
        if (x == l * 2)
            ans += max(dis[u], dis[v]) != l;
        else if (x > l * 2)
            ans += (dis[u] < l) + (dis[v] < l);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
