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

int n, m;
vi d, f;
int used[1010][1010];

inline int find(int u)
{
    return f[u] == u ? u : f[u] = find(f[u]);
}

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void Zlin()
{
    cin >> n >> m;
    d.assign(n + 1, 0);
    f.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        used[u][v] = used[v][u] = 1;
        ++d[u], ++d[v];
    }
    queue<int> d0, d1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1) d1.push(i);
        else if (d[i] == 0) d0.push(i);
    }
    vector<pii> ans;
    int l, r;
    if (d1.empty() && d0.size() >= 2)
    {
        l = d0.front(), d0.pop();
        r = d0.front(), d0.pop();
        used[l][r] = used[r][l] = 1;
        ans.push_back({l, r});
        d1.push(l);
        d1.push(r);
    }
    while (!d1.empty() && !d0.empty())
    {
        l = d1.front(), r = d0.front();
        d1.pop(), d0.pop();
        used[l][r] = used[r][l] = 1;
        ans.push_back({l, r});
        d1.push(r);
    }
    while (d1.size() >= 2)
    {
        l = d1.front(), d1.pop();
        r = d1.front(), d1.pop();
        used[l][r] = used[r][l] = 1;
        ans.push_back({l, r});
    }
    if (!d1.empty())
    {
        int top = d1.front();
        for (int i = 1; i <= n; i++)
            if (!used[top][i] && i != top && top != -1)
                ans.push_back({top, i}), top = -1;
        if (top != -1)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it.first << ' ' << it.second << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
