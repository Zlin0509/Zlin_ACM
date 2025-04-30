#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

struct edge
{
    int x1, x2;
    int y;
    int tag;
    bool operator<(edge &t)
    {
        return y < t.y;
    }
} E[200010]{};

struct tree
{
    int l, r;
    int cnt;
    int len;
} T[1600010]{};

int n;
int X[200010]{};
ll ans = 0;

inline void build(int l, int r, int u)
{
    T[u].l = l, T[u].r = r;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
}

inline void pushup(int u)
{
    int l = T[u].l, r = T[u].r;
    if (T[u].cnt)
        T[u].len = X[r + 1] - X[l];
    else
        T[u].len = T[u << 1].len + T[u << 1 | 1].len;
}

inline void add(int l, int r, int u, int tag)
{
    if (T[u].l > r || T[u].r < l)
        return;
    if (T[u].l >= l && T[u].r <= r)
    {
        T[u].cnt += tag;
        pushup(u);
        return;
    }
    add(l, r, u << 1, tag);
    add(l, r, u << 1 | 1, tag);
    pushup(u);
}

void solve()
{
    cin >> n;
    for (int i = 1, a, b, c, d; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        E[i] = {a, c, b, 1}, E[i + n] = {a, c, d, -1};
        X[i] = a, X[i + n] = c;
    }
    n *= 2;
    sort(E + 1, E + 1 + n);
    sort(X + 1, X + 1 + n);
    int s = unique(X + 1, X + 1 + n) - X - 1;
    build(1, s - 1, 1);
    for (int i = 1; i < n; i++)
    {
        int l = lower_bound(X + 1, X + s + 1, E[i].x1) - X;
        int r = lower_bound(X + 1, X + s + 1, E[i].x2) - X;
        // cout << l << " " << r << '\n';
        add(l, r - 1, 1, E[i].tag);
        ans += 1ll * T[1].len * (E[i + 1].y - E[i].y);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}