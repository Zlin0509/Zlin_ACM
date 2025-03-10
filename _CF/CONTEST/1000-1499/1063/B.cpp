//
// Created by Zlin on 2025/1/15.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int INF = 1e9;

int n, m, r, c, x, y;
vector<vi> a, cntl, cntr;

inline void Zlin()
{
    cin >> n >> m >> r >> c >> x >> y;
    a.assign(n + 1, vi(m + 1, 0));
    cntl.assign(n + 1, vi(m + 1, INF));
    cntr.assign(n + 1, vi(m + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        char c;
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = (c == '*');
        }
    }
    cntl[r][c] = cntr[r][c] = 0;
    queue<pii> q;
    q.push({r, c});
    auto check = [&](int x, int y)
    {
        return x >= 1 && x <= n && y >= 1 && y <= m && !a[x][y];
    };
    while (!q.empty())
    {
        pii u = q.front();
        q.pop();
        int xx = u.first, yy = u.second;
        int xxx, yyy;
        xxx = xx, yyy = yy - 1;
        if (check(xxx, yyy) && cntl[xx][yy] < x && cntl[xxx][yyy] > cntl[xx][yy] + 1)
        {
            cntl[xxx][yyy] = min(cntl[xxx][yyy], cntl[xx][yy] + 1);
            cntr[xxx][yyy] = min(cntr[xxx][yyy], cntr[xx][yy]);
            q.push({xxx, yyy});
        }
        xxx = xx, yyy = yy + 1;
        if (check(xxx, yyy) && cntr[xx][yy] < y && cntr[xxx][yyy] > cntr[xx][yy] + 1)
        {
            cntl[xxx][yyy] = min(cntl[xxx][yyy], cntl[xx][yy]);
            cntr[xxx][yyy] = min(cntr[xxx][yyy], cntr[xx][yy] + 1);
            q.push({xxx, yyy});
        }
        xxx = xx + 1, yyy = yy;
        if (check(xxx, yyy) && (cntl[xxx][yyy] > cntl[xx][yy] || cntr[xxx][yyy] > cntr[xx][yy]))
        {
            cntl[xxx][yyy] = min(cntl[xxx][yyy], cntl[xx][yy]);
            cntr[xxx][yyy] = min(cntr[xxx][yyy], cntr[xx][yy]);
            q.push({xxx, yyy});
        }
        xxx = xx - 1, yyy = yy;
        if (check(xxx, yyy) && (cntl[xxx][yyy] > cntl[xx][yy] || cntr[xxx][yyy] > cntr[xx][yy]))
        {
            cntl[xxx][yyy] = min(cntl[xxx][yyy], cntl[xx][yy]);
            cntr[xxx][yyy] = min(cntr[xxx][yyy], cntr[xx][yy]);
            q.push({xxx, yyy});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (min(cntl[i][j], cntr[i][j]) < INF)
                ++ans;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
