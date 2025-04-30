#include <bits/stdc++.h>
using namespace std;

int n, m, k;

struct edge
{
    int to, next, dis;
} e[10010]{};
int tot = 0, head[10010]{};

inline void add_edge(int u, int v, int dis)
{
    ++tot;
    e[tot].to = v;
    e[tot].dis = dis;
    e[tot].next = head[u];
    head[u] = tot;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1, x, y, d; i <= m; i++)
    {
        cin >> x >> y >> d;
        add_edge(x, y, d);
    }
    

}