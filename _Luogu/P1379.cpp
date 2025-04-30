#include <bits/stdc++.h>
using namespace std;

char now[4][4]{};
int k = 0, cc = 0;
map<int, pair<int, int>> fin;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};

bool check()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int z = now[i][j] - '0';
            if (fin[z].first != i || fin[z].second != j)
                return false;
        }
    }
    return true;
}

bool sum(int step)
{
    int cnt = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int z = now[i][j] - '0';
            if (fin[z].first != i || fin[z].second != j)
            {
                ++cnt;
                if (cnt + step > k)
                    return false;
            }
        }
    }
    return true;
}

void A_star(int x, int y, int step, int pre)
{
    if (check() || cc)
    {
        cc = 1;
        return;
    }
    if (step == k)
        return;
    for (int i = 0; i < 4; i++)
    {
        int xa = x + dx[i], ya = y + dy[i];
        if (ya > 3 || ya < 1 || xa > 3 || xa < 1 || pre + i == 3)
            continue;
        swap(now[xa][ya], now[x][y]);
        if (sum(step) && !cc)
            A_star(xa, ya, step + 1, i);
        swap(now[xa][ya], now[x][y]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fin[0] = {2, 2};
    fin[1] = {1, 1};
    fin[2] = {1, 2};
    fin[3] = {1, 3};
    fin[4] = {2, 3};
    fin[5] = {3, 3};
    fin[6] = {3, 2};
    fin[7] = {3, 1};
    fin[8] = {2, 1};

    int x, y;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            cin >> now[i][j];
            if (now[i][j] == '0')
                x = i, y = j;
        }

    if (check())
    {
        cout << 0 << '\n';
        return 0;
    }
    while (++k)
    {
        A_star(x, y, 0, -1);
        if (cc)
        {
            cout << k << '\n';
            return 0;
        }
    }
}