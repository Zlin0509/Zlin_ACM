#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int tot = 0, head[N];
struct edge
{
    int to, next;
} e[N];
inline void add(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int n, m, q;
inline void prework()
{
    
}
inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    prework();
    cin >> q;
    while (q--)
    {
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