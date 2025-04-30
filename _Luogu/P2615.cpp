#include <bits/stdc++.h>
using namespace std;

int n;
int a[44][44]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k = 1;
    int i = 1, j = (n + 1) / 2;
    while (k <= n * n)
    {
        a[i][j] = k;
        if(!a[(i-2+n)%n+1][j%n+1])
            i = (i - 2 + n) % n + 1, j = j % n + 1;
        else
            i = i % n + 1;
        ++k;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}