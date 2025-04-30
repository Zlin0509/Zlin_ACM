#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int n, m, s;
int tot = 0, head[2000010]{};
struct Edge
{
    int to, next, val;
} e[2000010]{};
void add_edge(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}

inline void Zlin()
{
    cin >> n >> m >> s;
    for (int i = 1, c; i <= m; i++)
    {
        cin >> c;
        if (c == 1)
        {
        }
        else
        {
        }
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