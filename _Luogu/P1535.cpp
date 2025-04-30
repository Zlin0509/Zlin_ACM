#include <bits/stdc++.h>
#define EL putchar('\n')
#define SP putchar(' ')
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m, t, r1, c1, r2, c2;
bitset<108> b[108];
int re[108][108][20];
int dfs(int x, int y, int time)
{
    if (re[x][y][time] != -1)
        return re[x][y][time];
    if (abs(x - r2) + abs(y - c2) > t - time)
        return re[x][y][time] = 0;
    if (time > t)
        return re[x][y][time] = 0;
    if (time == t)
    {
        if (x == r2 && y == c2)
            return re[x][y][time] = 1;
        else
            return re[x][y][time] = 0;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (b[x + dx[i]][y + dy[i]] || x + dx[i] < 1 || x + dx[i] > n || y + dy[i] < 1 || y + dy[i] > m)
            continue;
        ans += dfs(x + dx[i], y + dy[i], time + 1);
    }
    return re[x][y][time] = ans;
}
int main()
{
    cin >> n >> m >> t;
    memset(re, -1, sizeof(re));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*')
                b[i][j + 1] = 1;
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    cout << dfs(r1, c1, 0) << endl;
    return 0;
}