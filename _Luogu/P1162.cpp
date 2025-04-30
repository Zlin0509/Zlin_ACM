#include <bits/stdc++.h>
using namespace std;

int n;
int a[33][33]{};
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue<int> s;

void bfs(int x,int y)
{
    s.push(x);
    s.push(y);
    int xa, ya;
    while(!s.empty())
    {
        x = s.front();
        s.pop();
        y = s.front();
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            xa = x + dx[i];
            ya = y + dy[i];
            if (xa >= 0 && xa <= n + 1 && ya >= 0 && ya <= n + 1)
            {
                if(a[xa][ya]==0)
                {
                    a[xa][ya] = 2;
                    s.push(xa);
                    s.push(ya);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    bfs(0, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << 2 - a[i][j] << " ";
        cout << '\n';
    }
}