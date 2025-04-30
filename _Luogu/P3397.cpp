#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[1100][1100]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int x1, x2, y1, y2;
    while (m--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2;i++)
        {
            num[i][y1] += 1;
            num[i][y2 + 1] -= 1;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            num[i][j] += num[i][j - 1];
            cout << num[i][j] << ' ';
        }
        cout << '\n';
    }
}