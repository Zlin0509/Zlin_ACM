#include<bits/stdc++.h>
using namespace std;

int n;
int a[1010][1010]{};

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = max(a[i - 1][j], a[i - 1][j - 1]) + a[i][j];
            ans = max(ans, a[i][j]);
        }
    }
    cout << ans << '\n';
}