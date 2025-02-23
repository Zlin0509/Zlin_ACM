//
// Created by Zlin on 2025/2/22.
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

inline void Zlin()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vi tag(n + 1, 0);
    vector vis(n + 1, vi(n + 1, 0));
    vector dis(n + 1, vll(n + 1, 1e18));
    vector e1(n + 1, vi());
    vector e2(n + 1, vi());
    map<pii, int> tag1, tag2;
    int m;
    cin >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        e1[u].push_back(v);
        e1[v].push_back(u);
        if (u > v)
            swap(u, v);
        tag1[{u, v}] = 1;
    }
    cin >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        e2[u].push_back(v);
        e2[v].push_back(u);
        if (u > v)
            swap(u, v);
        tag2[{u, v}] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (tag1[{i, j}] && tag2[{i, j}])
                tag[i] = tag[j] = 1;
    dis[s1][s2] = 0;
    priority_queue<pair<ll, pii>> q;
    q.push({-dis[s1][s2], {s1, s2}});
    while (!q.empty())
    {
        s1 = q.top().second.first;
        s2 = q.top().second.second;
        q.pop();
        if (vis[s1][s2])
            continue;
        vis[s1][s2] = 1;
        for (int u1 : e1[s1])
        {
            for (int u2 : e2[s2])
            {
                if (dis[u1][u2] > dis[s1][s2] + abs(u1 - u2))
                {
                    dis[u1][u2] = dis[s1][s2] + abs(u1 - u2);
                    if (!vis[u1][u2])
                        q.push({-dis[u1][u2], {u1, u2}});
                }
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        if (tag[i])
            ans = min(ans, dis[i][i]);
    cout << (ans == 1e18 ? -1 : ans) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
