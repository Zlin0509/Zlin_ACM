#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

struct line
{
    ll x1, x2, y, val;
    bool operator<(const line &t)
    {
        if (y != t.y)
            return y < t.y;
        else
            return val > t.val;
    }
} L[100010]{};

struct tree
{
    ll l, r;
    ll val, mx;
} T[400010]{};

ll X[400010]{}, ans;
ll n, w, h;

void reclear()
{
    ans = 0;
    memset(T, 0, sizeof(T));
    memset(L, 0, sizeof(L));
}

void build(ll l, ll r, ll u)
{
    T[u].mx = 0, T[u].val = 0;
    T[u].l = l, T[u].r = r;
    if (l == r)
        return;
    ll mid = l + r >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
}

void pushdown(ll u)
{
    if (!T[u].val)
        return;
    T[u << 1].mx += T[u].val;
    T[u << 1 | 1].mx += T[u].val;
    T[u << 1].val += T[u].val;
    T[u << 1 | 1].val += T[u].val;
    T[u].val = 0;
}

void pushup(ll u)
{
    T[u].mx = max(T[u << 1].mx, T[u << 1 | 1].mx);
}

void add(ll u, ll l, ll r, ll val)
{
    if (T[u].l > r || T[u].r < l)
        return;
    if (T[u].l >= l && T[u].r <= r)
    {
        T[u].val += val;
        T[u].mx += val;
        return;
    }
    pushdown(u);
    ll mid = T[u].l + T[u].r >> 1;
    if (l <= mid)
        add(u << 1, l, r, val);
    if (mid < r)
        add(u << 1 | 1, l, r, val);
    pushup(u);
}

void solve()
{
    reclear();
    cin >> n >> w >> h;
    for (ll i = 1, x, y, l; i <= n; i++)
    {
        cin >> x >> y >> l;
        L[i] = {x, x + w - 1, y, l}, L[i + n] = {x, x + w - 1, y + h - 1, -l};
        X[i] = x, X[i + n] = x + w - 1;
    }
    n *= 2;
    sort(L + 1, L + 1 + n);
    sort(X + 1, X + 1 + n);
    ll s = unique(X + 1, X + 1 + n) - X - 1;
    build(1, s, 1);
    for (ll i = 1; i < n; i++)
    {
        int l = lower_bound(X + 1, X + 1 + n, L[i].x1) - X;
        int r = lower_bound(X + 1, X + 1 + n, L[i].x2) - X;
        // cout << l << " " << r << '\n';
        add(1, l, r, L[i].val);
        ans = max(ans, T[1].mx);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}