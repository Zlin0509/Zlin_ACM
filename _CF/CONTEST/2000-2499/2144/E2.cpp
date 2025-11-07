//
// Created by 27682 on 2025/11/5.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 3e5 + 5;
constexpr ll mo = 998244353;

int n, a[N];
ll vl[N], vr[N];
vi ls, rs;

struct Seg {
    struct Node {
        int val, tag;
    } t[N << 3];

    void pushdown(int i) {
        if (t[i].tag) {
            t[i].val = t[i].val * t[i].tag % mo;
            t[i << 1].tag = t[i << 1].tag * t[i].tag % mo;
            t[i << 1 | 1].tag = t[i << 1 | 1].tag * t[i].tag % mo;
            t[i].tag = 1;
        }
    }

    void build(int i, int l, int r) {
        t[i].tag = 1, t[i].val = 0;
        if (l == r) return;
        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }

    void add(int i, int l, int r, int x, int val) {
        if (l > x || r < x) return;
        pushdown(i);
        if (l == r) {
            t[i].val = (t[i].val + val) % mo;
            return;
        }
        int mid = l + r >> 1;
        add(i << 1, l, mid, x, val);
        add(i << 1 | 1, mid + 1, r, x, val);
    }

    void modify(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            t[i].tag = t[i].tag * 2 % mo;
            pushdown(i);
            return;
        }
        pushdown(i);
        int mid = l + r >> 1;
        modify(i << 1, l, mid, ql, qr);
        modify(i << 1 | 1, mid + 1, r, ql, qr);
    }

    int query(int i, int l, int r, int x) {
        if (l > x || r < x) return 0;
        pushdown(i);
        if (l == r) return t[i].val;
        int mid = l + r >> 1;
        return query(i << 1, l, mid, x) + query(i << 1 | 1, mid + 1, r, x);
    }
} seg;

inline void init() {
    ls.clear();
    rs.clear();
    for (int i = 1; i <= n; i++) vl[i] = vr[i] = 0;
}

inline void Zlin() {
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) if (ls.empty() || a[i] > ls.back()) ls.emplace_back(a[i]);
    for (int i = n; i; i--) if (rs.empty() || a[i] > rs.back()) rs.emplace_back(a[i]);
    int siz1 = ls.size(), siz2 = rs.size();
    seg.build(1, 0, siz1);
    seg.add(1, 0, siz1, 0, 1);
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(ls.begin(), ls.end(), a[i]) - ls.begin() + 1, tmp;
        if (a[i] == ls[x - 1]) tmp = seg.query(1, 0, siz1, x - 1);
        seg.modify(1, 0, siz1, x, siz1);
        if (a[i] == ls[x - 1]) seg.add(1, 0, siz1, x, tmp);
        vl[i] = (seg.query(1, 0, siz1, siz1) + seg.query(1, 0, siz1, siz1 - 1)) % mo;
    }
    seg.build(1, 0, siz2);
    seg.add(1, 0, siz2, 0, 1);
    for (int i = n; i; i--) {
        int x = lower_bound(rs.begin(), rs.end(), a[i]) - rs.begin() + 1, tmp;
        if (a[i] == rs[x - 1]) tmp = seg.query(1, 0, siz2, x - 1);
        seg.modify(1, 0, siz2, x, siz2);
        if (a[i] == rs[x - 1]) seg.add(1, 0, siz2, x, tmp);
        vr[i] = seg.query(1, 0, siz2, siz2 - 1);
    }
    if (siz1 == 1) vl[0] = 1;
    if (siz2 == 1) vr[n + 1] = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) if (a[i] == ls.back()) ans = (ans + vl[i - 1] * vr[i + 1] % mo) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
