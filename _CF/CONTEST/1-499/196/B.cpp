//
// Created by Zlin on 2025/1/20.
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

const int N = 1510;

struct Node
{
    bool is_find;
    int x, y;
} vis[N][N];

char s[N][N];
int n, m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool dfs(int x, int y, int xx, int yy)
{
    if (vis[x][y].is_find)
    {
        // 之前来过
        if (xx == vis[x][y].x and yy == vis[x][y].y) // 是在同一矩阵内
            return false;
        return true;
    }
    vis[x][y].is_find = true;
    vis[x][y].x = xx;
    vis[x][y].y = yy;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i], nxx = xx, nyy = yy;
        if (nx < 1)
        {
            nxx--;
            nx = n;
        }
        else if (nx > n)
        {
            nxx++;
            nx = 1;
        }
        if (ny < 1)
        {
            nyy--;
            ny = m;
        }
        else if (ny > m)
        {
            nyy++;
            ny = 1;
        }
        if (s[nx][ny] == '#') continue;
        if (dfs(nx, ny, nxx, nyy))
            return true;
    }
    return false;
}


inline void Zlin()
{
    cin >> n >> m;
    int sx, sy;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            vis[i][j].is_find = false;
        }
    }
    if (dfs(sx, sy, 0, 0))
        puts("Yes");
    else
        puts("No");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
