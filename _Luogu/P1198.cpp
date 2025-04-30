#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll m, d, x, num = 0, t = 0;
char c;
ll a[200010]{}, f[200010][33]{};

void ST_prework()
{
    f[num][0] = a[num];
    int t = log(num) / log(2) + 1;
    for (int j = 1; j < t; j++)
    {
        f[num - (1 << j) + 1][j] = max(f[num - (1 << j) + 1][j - 1], f[num - (1 << (j - 1))][j - 1]);
        f[num - (1 << j) + 1][j] = max(f[num - (1 << j) + 1][j], a[num]);
    }
}

ll ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> d;

    for (int i = 1; i <= m; i++)
        a[i] = -0x3f3f3f3f;

    while (m--)
    {
        cin >> c >> x;
        if (c == 'A')
        {
            x = (x + t) % d;
            a[++num] = x;
            ST_prework();
        }
        else
        {
            t = ST_query(num - x + 1, num);
            cout << t << '\n';
        }
    }
}