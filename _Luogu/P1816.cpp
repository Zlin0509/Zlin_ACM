#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int m, n, x, y;
int a[100010]{}, f[100010][32]{};

void ST_prework()
{
    for (int i = 1; i <= m; i++)
        f[i][0] = a[i];
    int t = log(m) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= m - (1 << j) + 1; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    ST_prework();
    while (n--)
    {
        cin >> x >> y;
        cout << ST_query(x, y) << ' ';
    }
}