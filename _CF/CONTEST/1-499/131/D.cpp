//
// Created by Zlin on 2025/1/15.
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

int n;
vector<vi> e;
vi have, fa, vis, ans;

inline bool dfs(int u, int f)
{
    vis[u] = 1;
    fa[u] = f;
    for (auto v : e[u])
    {
        if (v == f) continue;
        if (!vis[v])
        {
            if (dfs(v, u)) return true;
        }
        else
        {
            int now = u;
            while (now != v)
            {
                have.push_back(now);
                now = fa[now];
            }
            have.push_back(v);
            return true;
        }
    }
    return false;
}

inline void Zlin()
{
    cin >> n;
    e.assign(n + 1, vi());
    fa.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    ans.assign(n + 1, 5000);
    for (int i = 1, u, v; i <= n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    queue<int> q;
    for (auto it : have) ans[it] = 0, q.push(it);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
        {
            if (ans[v] != 5000) continue;
            ans[v] = ans[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
