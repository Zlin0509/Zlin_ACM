#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<pair<int, int>> t[100010]{};
int ans[100010]{}, vis[100010]{};

void bfs()
{
    queue<int> q;
    q.push(s);
    int u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto it : t[u])
        {
            if (ans[u] + it.second < ans[it.first])
            {
                ans[it.first] = ans[u] + it.second;
                if (!vis[it.first])
                    q.push(it.first);
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
        ans[i] = 0x7fffffff;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        t[u].push_back({v, w});
    }

    ans[s] = 0;
    bfs();

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}