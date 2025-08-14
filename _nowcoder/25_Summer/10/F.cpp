#include <bits/stdc++.h>
using namespace std;
using ll = int;
using lb = double;
using ull = unsigned long long;
const int N = 1e6 + 5;
const int M = 10010;
const ll inf = 1e18;
const ll mod = 998244353;
const ull base = 131;
ll n, a[N], b[N];

struct Node {
    ll p, l, r, data, x, laz;
} t[N << 2];

ll mp[N], lst[N];
pair<ll, ll> c[N];

void update(ll p) {
    if (t[p * 2].data > t[p * 2 + 1].data) {
        t[p].data = t[p * 2].data;
        t[p].x = t[p * 2].x;
        return;
    } else {
        t[p].data = t[p * 2 + 1].data;
        t[p].x = t[p * 2 + 1].x;
    }
}

void build(ll p, ll l, ll r) {
    t[p].l = l;
    t[p].r = r;
    t[p].laz = 0;
    if (l == r) {
        t[p].data = 0;
        t[p].x = l;
        return;
    }
    ll mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
}

void spread(ll p) {
    if (t[p].laz) {
        t[p * 2].data += t[p].laz;
        t[p * 2].laz += t[p].laz;
        t[p * 2 + 1].data += t[p].laz;
        t[p * 2 + 1].laz += t[p].laz;
        t[p].laz = 0;
    }
}

void change(ll p, ll l, ll r, ll data) {
    if (l <= t[p].l && t[p].r <= r) {
        t[p].data += data;
        t[p].laz += data;
        return;
    }
    spread(p);
    ll mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid) change(p * 2, l, r, data);
    if (r > mid) change(p * 2 + 1, l, r, data);
    update(p);
}

pair<ll, ll> getnum(ll p, ll l, ll r) {
    if (l <= t[p].l && t[p].r <= r) {
        return {t[p].data, t[p].x};
    }
    spread(p);
    ll mid = t[p].l + t[p].r >> 1;
    pair<ll, ll> res = {0, 0};
    if (l <= mid) res = max(res, getnum(p * 2, l, r));
    if (r > mid) res = max(res, getnum(p * 2 + 1, l, r));
    return res;
}

void solve() {
    cin >> n;
    memset(mp, 0, sizeof(mp));
    memset(lst, 0, sizeof(lst));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        b[i] = mp[a[i]];
        mp[a[i]] = i;
        if (!lst[a[i]]) lst[a[i]] = i;
    }
    build(1, 1, n);
    ll b1 = 2, b2 = 3, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == mp[a[i]]) {
            ll l = b[i], r = lst[a[i]];
            // cout << l+1 << " " << r << "\n";
            if (l + 1 <= r)change(1, l + 1, r, 1);
            c[a[i]] = {l + 1, r};
        }
        if (b[i] == lst[a[i]] && c[a[i]].first) {
            // cout << l+1 << " " << r << "\n";
            change(1, c[a[i]].first, c[a[i]].second, -1);
        }
        if (i + 2 <= n) {
            pair<ll, ll> xx = getnum(1, i + 2, n);
            if (xx.first > ans) {
                ans = xx.first;
                b1 = i + 1, b2 = xx.second;
            }
        }
    }
    cout << ans << "\n";
    cout << b1 << " " << b2 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
