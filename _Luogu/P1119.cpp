#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
int x, y, t;
int a[N];
int f[220][220];
inline void update(int k)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (f[i][j] > f[i][k] + f[j][k])
                f[i][j] = f[j][i] = f[i][k] + f[j][k];
}
inline void Zlin()
{
    for (int i = 0; i <= 200; i++)
        for (int j = 0; j <= 200; j++)
            f[i][j] = 1e9;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = w;
    }
    cin >> q;
    int tag = 0;
    while (q--)
    {
        cin >> x >> y >> t;
        while (a[tag] <= t && tag < n)
        {
            update(tag);
            ++tag;
        }
        if (a[x] > t || a[y] > t || f[x][y] == 1e9)
            cout << "-1" << '\n';
        else
            cout << f[x][y] << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}