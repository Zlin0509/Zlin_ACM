#include <bits/stdc++.h>
using namespace std;

int f[30010]{}, d[30010]{}, cnt[30010]{};

int Get(int x)
{
    if (x == f[x])
        return x;
    int root = Get(f[x]);
    d[x] += d[f[x]];
    return f[x] = root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 30000; i++)
        d[i] = 0, f[i] = i, cnt[i] = 1;
    char c;
    int x, y, T, fx, fy;
    cin >> T;
    while (T--)
    {
        cin >> c >> x >> y;
        fx = Get(x);
        fy = Get(y);
        if (c == 'M')
        {
            d[fx] += cnt[fy];
            f[fx] = fy;
            cnt[fy] += cnt[fx];
            cnt[fx] = 0;
        }
        else
        {
            if (fx != fy)
                cout << "-1" << '\n';
            else
                cout << abs(d[x] - d[y]) - 1 << '\n';
        }
    }
}