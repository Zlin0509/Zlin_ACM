
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, m;
char c, a[N];
int f[N];
inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }
inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
}
inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[i] = i;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        if (a[u] == a[v])
            merge(u, v);
    }
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v >> c;
        int fx = find(u), fy = find(v);
        if (fx == fy && a[u] != c)
            cout << 0;
        else
            cout << 1;
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