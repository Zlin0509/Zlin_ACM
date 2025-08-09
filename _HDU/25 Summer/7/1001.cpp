//
// Created by 27682 on 2025/8/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Seg {
    static constexpr int N = 5e4;

    struct Node {
        int l, r;
        int val, tag;
    } t[N];

    void pushdown(int i) {
        if (t[i].l != t[i].r) {
            t[i << 1].val += t[i].tag;
            t[i << 1].tag += t[i].tag;
            t[i << 1 | 1].val += t[i].tag;
            t[i << 1 | 1].tag += t[i].tag;
        }
        t[i].tag = 0;
    }

    void update(int i) {
        t[i].val = max(t[i << 1].val, t[i << 1 | 1].val);
    }

    void build(int i, int l, int r) {
        t[i] = {l, r, 0, 0};
        if (l == r) return;
        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }

    void modify(int i, int l, int r, int val) {
        if (t[i].r < l || t[i].l > r) return;
        if (t[i].l >= l && t[i].r <= r) {
            t[i].val += val;
            t[i].tag += val;
            return;
        }
        pushdown(i);
        modify(i << 1, l, r, val);
        modify(i << 1 | 1, l, r, val);
        update(i);
    }

    int query() {
        return t[1].val;
    }
} seg;

constexpr int N = 1e4 + 10;

int n, k, ans;
array<int, 3> a[N];
vector<pii> idx[N];

inline int cal(int h, int w) {
    int res = 0;
    seg.build(1, 1, n);
    for (int i = 1; i <= min(h, n); i++) {
        for (auto [pos, val]: idx[i]) {
            seg.modify(1, max(1, pos - w + 1), pos, val);
        }
    }
    res = max(res, seg.query());
    for (int i = h + 1, j; i <= n; i++) {
        j = i - h;
        for (auto [pos, val]: idx[j]) seg.modify(1, max(1, pos - w + 1), pos, -val);
        for (auto [pos, val]: idx[i]) seg.modify(1, max(1, pos - w + 1), pos, val);
        res = max(res, seg.query());
    }
    return res;
}

inline void Zlin() {
    cin >> n >> k;
    ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 1; i <= n; i++) idx[i].clear();
    for (int i = 0; i < n; i++) idx[a[i][0]].emplace_back(a[i][1], a[i][2]);
    for (int i = 1; i * i <= k; i++) ans = max(ans, cal(i, k / i));
    for (int i = 1; i <= n; i++) idx[i].clear();
    for (int i = 0; i < n; i++) idx[a[i][1]].emplace_back(a[i][0], a[i][2]);
    for (int i = 1; i * i <= k; i++) ans = max(ans, cal(i, k / i));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
