#include <bits/stdc++.h>
using namespace std;

int dx[8] = {2, 1, 2, 1, -1, -2, -1, -2}, dy[8] = {1, 2, -1, -2, 2, 1, -2, -1};
int k = 0, cc = 0, ans = 0;
char M[6][6] = {
    {'1', '1', '1', '1', '1', '1'},
    {'1', '1', '1', '1', '1', '1'},
    {'1', '0', '1', '1', '1', '1'},
    {'1', '0', '0', '*', '1', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0'}};

char now[6][6]{};

bool check()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (M[i][j] != now[i][j])
                return false;
    return true;
}

bool guess(int step)
{
    int cnt = step;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (now[i][j] != M[i][j] && ++cnt > k)
                return false;
    return true;
}

void IDA(int x, int y, int step, int pre)
{
    if (check() || cc)
    {
        cc = 1;
        return;
    }
    if (step > k)
        return;
    for (int i = 0; i < 8; i++)
    {
        int xa = x + dx[i], ya = y + dy[i];
        if (xa > 5 || xa < 1 || ya > 5 || ya < 1 || pre + i == 7)
            continue;
        swap(now[x][y], now[xa][ya]);
        if (guess(step))
            IDA(xa, ya, step + 1, i);
        swap(now[x][y], now[xa][ya]);
    }
}

void solve()
{
    int x, y;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
        {
            cin >> now[i][j];
            if (now[i][j] == '*')
                x = i, y = j;
        }
    if (check())
    {
        cout << 0 << '\n';
        return;
    }
    cc = 0, k = 0;
    while (++k && k <= 15)
    {
        IDA(x, y, 0, -1);
        if (cc)
        {
            cout << k << '\n';
            return;
        }
    }
    cout << "-1" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}