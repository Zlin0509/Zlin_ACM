//
// Created by Zlin on 2025/1/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll INF = 1e14;
constexpr int N = 1e5 + 10;

struct edge
{
    int to, nxt, val;
} e[N << 1];

int tot = 0, head[N << 1];

inline void add(int u, int v, int val)
{
    e[++tot] = {v, head[u], val};
    head[u] = tot;
}

int n, m;
vi vis, pre;
vll dis;

inline void dij(int s)
{
    priority_queue<pair<ll, int>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].val;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pre[v] = u;
                if (!vis[v])
                    q.push({-dis[v], v});
            }
        }
    }
}

inline void Zlin()
{
    cin >> n >> m;
    pre.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    dis.assign(n + 1, INF);
    for (int i = 1, u, v, val; i <= m; i++)
    {
        cin >> u >> v >> val;
        add(u, v, val);
        add(v, u, val);
    }
    dij(1);
    if (!vis[n])
    {
        cout << -1 << '\n';
    }
    else
    {
        stack<int> ans;
        int tag = n;
        while (tag)
        {
            ans.push(tag);
            tag = pre[tag];
        }
        while (!ans.empty())
        {
            cout << ans.top() << ' ';
            ans.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
