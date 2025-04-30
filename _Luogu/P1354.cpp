#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int head[110]{}, vis[110]{};
double dis[22][5]{};

struct edge
{
    int to, next;
    double dis;
} e[110]{};

inline void add_edge(int u, int v, double dis)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].dis = dis;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void dijkstra()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    double x, xa, xb, ya, yb;
    
}