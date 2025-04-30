#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int n, m;
int a[110][110]{}, num[110][110]{};
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs(int xa,int ya)
{
    if(num[xa][ya])
        return num[xa][ya];

    int x, y;
    num[xa][ya] = 1;
    for (int i = 0; i < 4;i++)
    {
        x = xa + dx[i];
        y = ya + dy[i];
        if(x>=1&&x<=n&&y>=1&&y<=m&&a[xa][ya]>a[x][y])
        {
            dfs(x, y);
            num[xa][ya] = max(num[xa][ya], num[x][y] + 1);
        }
    }
    return num[xa][ya];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << '\n';
}