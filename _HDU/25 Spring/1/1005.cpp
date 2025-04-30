//
// Created by 27682 on 2025/3/7.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

vector<vll> t, d;
vector<vector<vll>> vis, dis;

struct type
{
    int x, y;
    int op;
    ll val;

    bool operator<(const type& a) const
    {
        return val > a.val;
    }
};

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

inline void Zlin()
{
    cin >> n >> m;
    t.assign(n + 1, vll(m + 1, 0));
    d.assign(n + 1, vll(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    vis.assign(n + 1, vector(m + 1, vll(4, 0)));
    dis.assign(n + 1, vector(m + 1, vll(4, 1e16)));
    priority_queue<type> q;
    q.push({1, 1, 1, 0});
    dis[1][1][1] = 0;
    auto check1 = [&](int x, int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };
    while (!q.empty())
    {
        type zz = q.top();
        q.pop();
        int x = zz.x, y = zz.y, op = zz.op;
        if (vis[x][y][op])
            continue;
        vis[x][y][op] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (!check1(xx, yy))
                continue;
            if (dis[xx][yy][i] > dis[x][y][op] + (i == op ? 0 : d[x][y]) + t[x][y])
            {
                dis[xx][yy][i] = dis[x][y][op] + (i == op ? 0 : d[x][y]) + t[x][y];
                q.push({xx, yy, i, dis[xx][yy][i]});
            }
        }
    }
    ll ans = 1e16;
    for (int i = 0; i < 4; i++)
        ans = min(ans, dis[n][m][i] + t[n][m] + (i == 2 ? 0 : d[n][m]));
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
