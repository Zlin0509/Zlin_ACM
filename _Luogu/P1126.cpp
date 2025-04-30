#include <bits/stdc++.h>
using namespace std;

int xa, ya, xb, yb;
char Tow;
int n, m, T;
int M[55][55]{};
int a[55][55]{};
int f[55][55]{};
struct node
{
    int x, y;
    int t;
    int time;
};
queue<node> s;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int abc[4] = {0, 1, 2, 1};
int ft[4] = {0, 3, 1, 2}; // 0上，3右，1下，2左;
int fft[4] = {0, 2, 3, 1}; // 对应上下左右;

void change()
{
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(M[i][j]==1)
            {
                a[i - 1][j] = 1;
                a[i][j - 1] = 1;
                a[i - 1][j - 1] = 1;
                a[i][j] = 1;
            }
        }
    }
}

void bfs()
{
    node u;
    while(!s.empty())
    {
        u = s.front();
        s.pop();
        for (int i = 0; i < 4;i++)
        {
            int zhuan = abc[i];
            int fangx = fft[u.t] + i;
            if (fangx == 5)
                fangx = 0;
            if (fangx == 6)
                fangx = 1;
            if (fangx == 7)
                fangx = 2;
            if (fangx == 8)
                fangx = 3;
            fangx = ft[fangx];

        }
    }
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
            cin >> M[i][j];
        }
    }
    cin >> xa >> ya >> xb >> yb;
    cin >> Tow;

    if(Tow=='W')
        T = 2;
    else if(Tow=='E')
        T = 3;
    else if(Tow=='S')
        T = 1;
    else
        T = 0;
    
    change();

    node first;
    first.x = xa;
    first.y = ya;
    first.t = T;
    first.time = 0;
    s.push(first);
    bfs();


}