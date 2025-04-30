#include "bits/stdc++.h"
using namespace std;

int n, m;
int check[110][110];
char a[110][110];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> tt;
queue<pair<int, int>> q;
inline void dfs(int x, int y, int type, int dep)
{
    int xx = x + dx[type], yy = y + dy[type];
    if (xx > n || xx < 1 || yy > m || yy < 1 || a[xx][yy] == '*' || check[xx][yy] < dep)
        return;
    check[xx][yy] = dep;
    q.push({xx, yy});
    dfs(xx, yy, type, dep);
}
inline void bfs()
{
    q.push(tt[0]);
    check[tt[0].first][tt[0].second] = 0;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
            dfs(u.first, u.second, i, check[u.first][u.second] + 1);
    }
}
inline void Zlin()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            check[i][j] = 1e8;
            cin >> a[i][j];
            if (a[i][j] == 'C')
                tt.push_back({i, j});
        }
    bfs();
    cout << check[tt[1].first][tt[1].second] - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}