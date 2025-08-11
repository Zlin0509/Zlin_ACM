#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const ll inf = 1e18;
ll n, a[N << 1], q;

struct Matrix {
    int n;
    ll a[4][4];

    ll *operator [](int i) {
        return a[i];
    }

    Matrix operator *(Matrix b) {
        Matrix c = {};
        c.n = 4;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = -inf;
                for (int k = 0; k < n; k++) {
                    c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
        return c;
    }
};

struct Node {
    ll l, r;
    Matrix m;
} t[N << 2];

inline void update(ll p) {
    t[p].m = t[p * 2].m * t[p * 2 + 1].m;
}

void build(ll p, ll l, ll r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].m.n = 4;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                t[p].m[j][k] = -inf;
            }
        }
        for (int j = 0; j < 4; j++) t[p].m[j][0] = 0;
        for (int j = 1; j < 4; j++) t[p].m[j - 1][j] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
}

void change(ll p, ll x, ll y) {
    if (t[p].l == t[p].r) {
        for (int j = 1; j < 4; j++) t[p].m[j - 1][j] = y;
        return;
    }
    ll mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid) change(p * 2, x, y);
    else change(p * 2 + 1, x, y);
    update(p);
}

Matrix getnum(ll p, ll l, ll r) {
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].m;
    }
    ll mid = (t[p].l + t[p].r) >> 1;
    Matrix res;
    if (l <= mid) res = getnum(p * 2, l, r);
    if (r > mid) {
        if (l <= mid) res = res * getnum(p * 2 + 1, l, r);
        else res = getnum(p * 2 + 1, l, r);
    }
    return res;
}

inline ll query() {
    ll res = 0;
    for (int i = 0; i < 3; i++) {
        ll l = i + 1, r = i + n - 1;
        Matrix xx = getnum(1, l, r);
        for (int j = 0; j < 4; j++) res = max(res, xx[0][j]);
    }
    return res;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    build(1, 1, n + 3);
    cout << query() << "\n";
    while (q--) {
        ll x, y;
        cin >> x >> y;
        change(1, x, y);
        if (x <= 3) change(1, x + n, y);
        cout << query() << "\n";
    }
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
