#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, t;
int a[N], dis[N];
int tot = 0, head[N << 1];
struct edge
{
    int to, next, val;
} e[N << 1];
inline void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}
inline void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa)
        {
            dis[e[i].to] = dis[u] + e[i].val;
            dfs(e[i].to, u);
        }
}
struct ST
{
    struct node
    {
        ll v1, v2, v3, v4;
        friend node operator+(const node &x, const node &y)
        {
            node res;
            res.v1 = std::max(x.v1, y.v1);
            res.v2 = std::min(x.v2, y.v2);
            res.v3 = std::max(x.v3, y.v3);
            res.v4 = std::min(x.v4, y.v4);
            return res;
        }
    } st[N][20];
    void init()
    {
        for (int i = 1; i <= n; ++i)
            st[i][0].v1 = st[i][0].v2 = 1ll * dis[i] * dis[i] * dis[i] + a[i],
            st[i][0].v3 = st[i][0].v4 = 1ll * dis[i] * dis[i] * dis[i] - a[i];
        int t = log(n) / log(2) + 1;
        for (int j = 1; j < t; j++)
            for (int i = 1; i <= n - (1ll << j) + 1; i++)
                st[i][j] = st[i][j - 1] + st[i + (1ll << (j - 1))][j - 1];
    }
    node ask(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return st[l][k] + st[r - (1ll << k) + 1][k];
    }
} st;
inline void Zlin()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v, val; i < n; i++)
    {
        cin >> u >> v >> val;
        add(u, v, val);
        add(v, u, val);
    }
    dfs(1, 0);
    st.init();
    int l1, l2, r1, r2;
    ST::node l, r;
    while (t--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        l = st.ask(l1, r1), r = st.ask(l2, r2);
        cout << max(max(l.v1 - r.v2, l.v3 - r.v4), max(r.v1 - l.v2, r.v3 - l.v4)) << '\n';
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