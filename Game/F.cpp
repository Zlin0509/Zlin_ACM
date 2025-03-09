//
// Created by Zlin on 2025/3/9.
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

constexpr ll inf = 1e12;

int n, m;
vector<vi> ee, e1, e2;
ll dep[110];

inline void bfs()
{
    for (int i = 1; i <= n; i++)
        dep[i] = inf;
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : ee[u])
            if (dep[v] > dep[u] + 1)
            {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
    }
}

ll in1[110], in2[110];

ll vis[110];

inline void work()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v : ee[u])
            if (dep[v] == dep[u] + 1)
            {
                e1[u].push_back(v);
                ++in1[v];
                e2[v].push_back(u);
                ++in2[u];
                q.push(v);
            }
    }
}


ll cnt1[110], cnt2[110];

inline void topo1()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in1[i])
            q.push(i), cnt1[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : e1[u])
        {
            --in1[v];
            cnt1[v] += cnt1[u];
            if (!in1[v])
                q.push(v);
        }
    }
}

inline void topo2()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in2[i])
            q.push(i), cnt2[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : e2[u])
        {
            --in2[v];
            cnt2[v] += cnt2[u];
            if (!in2[v])
                q.push(v);
        }
    }
}

inline void Zlin()
{
    cin >> n >> m;
    ee.assign(n + 1, vi());
    e1.assign(n + 1, vi());
    e2.assign(n + 1, vi());
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        ee[u].push_back(v);
        ee[v].push_back(u);
    }
    bfs();
    work();
    topo1();
    topo2();
    ll p = 0, q = 0;
    for (int i = 2; i <= n; i++)
    {
        if (e1[i].empty())
        {
            q += cnt1[i];
            p = max(p, cnt1[i]);
        }
        else
        {
            p = max(p, cnt1[i] * cnt2[i] * 2);
        }
    }

    ll z = gcd(p, q);
    p /= z, q /= z;
    printf("%.012lf", (db)p / q);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
