#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int a[410][410]{};
queue<int> s;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void bfs(int time)
{
    if(s.empty())
        return;
    queue<int> s1;
    int xa, ya;
    while(!s.empty())
    {
        x = s.front();
        s.pop();
        y = s.front();
        s.pop();
        for (int i = 0; i < 8;i++)
        {
            xa = x + dx[i];
            ya = y + dy[i];
            if(xa>=1&&xa<=n&&ya>=1&&ya<=m)
            {
                if(a[xa][ya]==-1)
                {
                    s1.push(xa);
                    s1.push(ya);
                    a[xa][ya] = time;
                }
            }
        }
    }
    s = s1;
    bfs(time + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = -1;
    a[x][y] = 0;
    s.push(x);
    s.push(y);
    bfs(1);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}