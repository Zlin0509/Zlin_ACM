//
// Created by Zlin on 2025/1/23.
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

int n, m, ans = INT_MAX;
vector<vi> a, vis;
set<pii> have;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

inline bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

inline void find(int x, int y)
{
    queue<pii> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto [i,j] = q.front();
        q.pop();
        if (vis[i][j] || !a[i][j])
            continue;
        vis[i][j] = 1;
        for (int k = 0, xx, yy; k < 4; k++)
        {
            xx = i + dx[k];
            yy = j + dy[k];
            if (!check(xx, yy) || vis[xx][yy])
                continue;
            if (a[xx][yy])
                q.push({xx, yy});
            else
                have.insert({xx, yy});
        }
    }
    ans = min(ans, (int)have.size());
    have.clear();
}

inline void Zlin()
{
    cin >> n >> m;
    a.assign(n + 1, vi(m + 1));
    vis.assign(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && a[i][j])
                find(i, j);
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
