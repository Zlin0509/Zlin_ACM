//
// Created by Zlin on 2024/12/26.
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

int n, ans = 0;
vi l, l1, l2, r, r1, r2;
vector<vi> e;

inline void dfs(int u, int fa)
{
    int top1 = 0, top2 = 0, cnt = 0;
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        ++cnt;
        dfs(v, u);
        l2[u] = max(l2[u], l2[v]);
        if (l[v] + 1 > top1)
        {
            top2 = top1;
            top1 = l[v] + 1;
        }
        else top2 = max(top2, l[v] + 1);
    }
    if (cnt >= 1) l1[u] += top1, l[u] = top1;
    if (cnt >= 2) l1[u] += top2;
    l2[u] = max(l2[u], l1[u]);
}

inline void dfs1(int u, int fa)
{
    int top1 = 0, top2 = 0, cnt = 0;
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        ++cnt;
        dfs1(v, u);
        r2[u] = max(r2[u], r2[v]);
        if (r[v] + 1 > top1)
        {
            top2 = top1;
            top1 = r[v] + 1;
        }
        else top2 = max(top2, r[v] + 1);
    }
    if (cnt >= 1) r1[u] = r[u] = top1;
    if (cnt >= 2) r1[u] += top2;
    r2[u] = max(r2[u], r1[u]);
}

inline void dfs2(int u, int fa)
{
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        r.assign(n + 1, 0);
        r1.assign(n + 1, 0);
        r2.assign(n + 1, 0);
        dfs1(u, v);
        ans = max(ans, l2[v] * r2[u]);
        dfs2(v, u);
    }
}

inline void Zlin()
{
    cin >> n;
    l.assign(n + 1, 0);
    l1.assign(n + 1, 0);
    l2.assign(n + 1, 0);
    e.assign(n + 1, vi());
    for (int i = 0, u, v; i < n - 1; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
