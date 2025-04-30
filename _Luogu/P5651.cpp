#include <bits/stdc++.h>
using namespace std;

int n, m, Q;
long long dis[100010]{}, ans;
int used[100010]{};
vector<pair<int, long long>> t[100010]{};

inline void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (used[u])
            continue;
        used[u] = 1;
        for (auto it : t[u])
        {
            if (used[it.first])
                continue;
            q.push(it.first);
            dis[it.first] = dis[u] ^ it.second;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> Q;
    for (int i = 1, x, y, v; i <= m; i++)
    {
        cin >> x >> y >> v;
        t[x].push_back({y, v});
        t[y].push_back({x, v});
    }

    bfs(1);

    int x, y;
    while (Q--)
    {
        cin >> x >> y;
        ans = dis[x] ^ dis[y];
        cout << ans << '\n';
    }
}