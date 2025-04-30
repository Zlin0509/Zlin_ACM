#include<bits/stdc++.h>
using namespace std;

int n;
int a[130][130]{};

int check(int x1,int y1,int x2,int y2)
{
    return a[x1][y1] + a[x2 - 1][y2 - 1] - a[x1][y2 - 1] - a[x2 - 1][y1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1,x; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            a[i][j] = a[i][j - 1] + x + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x2 = 1; x2 <= i; x2++)
            {
                for (int y2 = 1; y2 <= j; y2++)
                {
                    ans = max(ans, check(i, j, x2, y2));
                }
            }
        }
    }
    cout << ans << '\n';
}