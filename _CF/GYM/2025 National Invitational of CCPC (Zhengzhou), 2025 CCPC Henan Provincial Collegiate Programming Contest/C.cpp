//
// Created by Zlin on 2025/10/19.
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

constexpr int N = 4e5 + 10;

struct Seg {
    struct Node {
        int l, r;
        int val, tag, id;
    } t[N << 2];

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
        if (t[i << 1].val >= t[i << 1 | 1].val) t[i].id = t[i << 1].id;
        else t[i].id = t[i << 1 | 1].id;
    }

    void build(int i, int l, int r) {
        t[i] = {l, r, 0, 0, l};
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

    pii query() {
        return {t[1].id, t[1].val};
    }
} seg;

int n, m;
int rs[N], a[N];

set<int> st;

pii ans;

inline void Zlin() {
    cin >> n >> m;
    st.clear();
    seg.build(1, 1, n * 2 + 10);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int lx = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1] + 1) {
            rs[i - 1] = lx;
            st.insert(i - 1);
            lx = i;
        }
    }
    rs[n] = lx;
    st.insert(n);
    for (const auto &rx: st) {
        lx = rs[rx];
        seg.modify(1, a[lx], a[rx], 1);
    }
    ans = seg.query();
    cout << ans.first << ' ' << ans.second << endl;
    while (m--) {
        int l, r, d;
        cin >> l >> r >> d;
        while (st.lower_bound(l) != st.end() && rs[*st.lower_bound(l)] <= r) {
            auto it = st.lower_bound(l);
            int rx = *it, lx = rs[rx];
            st.erase(it);
            seg.modify(1, a[lx], a[rx], -1);
            if (lx < l) {
                rs[l - 1] = lx;
                a[l - 1] = a[lx] + l - 1 - lx;
                st.insert(l - 1);
                seg.modify(1, a[lx], a[l - 1], 1);
            }
            if (rx > r) {
                rs[rx] = r + 1;
                a[r + 1] = a[rx] - rx + (r + 1);
                st.insert(rx);
                seg.modify(1, a[r + 1], a[rx], 1);
            }
        }
        a[l] = d, a[r] = d + r - l;
        rs[r] = l;
        st.insert(r);
        seg.modify(1, a[l], a[r], 1);
        ans = seg.query();
        cout << ans.first << ' ' << ans.second << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
