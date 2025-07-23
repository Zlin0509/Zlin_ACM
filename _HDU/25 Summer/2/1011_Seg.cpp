//
// Created by 27682 on 2025/7/21.
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

constexpr int N = 5.1e5 + 10;

int n, m;
int a[N];

namespace Seg {
    struct Node {
        int len, le, rg, cnt, over;
        int st, ed;

        void init(int x) {
            len = 1;
            le = rg = x == 0;
            cnt = x == 1;
            over = 0;
            st = ed = -1;
        }

        int cal() {
            if (!cnt) return 0;
            if (cnt == 1) return rg;
            if (ed == rg + 1) return st + 2 * (st - ed + 1);
            return rg;
        }
    } t[N << 2];

    Node operator+(Node lx, Node rx) {
        Node self;
        self.len = lx.len + rx.len;
        self.cnt = lx.cnt + rx.cnt;
        self.le = lx.le == lx.len ? lx.len + rx.le : lx.le;
        self.rg = rx.rg == rx.len ? rx.len + lx.rg : rx.rg;
        if (self.cnt < 2) {
            self.over = 0;
            self.st = self.ed = -1;
            return self;
        }
        if (!rx.cnt) {
            self.over = lx.over;
            self.st = lx.st, self.ed = lx.ed;
            return self;
        }
        if (!lx.cnt) {
            self.over = rx.over;
            self.st = rx.st, self.ed = rx.ed;
            return self;
        }
        if (rx.over) {
            self.over = 1;
            self.st = rx.st, self.ed = rx.ed;
            return self;
        }
        int mid = lx.rg + rx.le;
        if (lx.cnt == 1 && rx.cnt == 1) {
            self.over = 0;
            self.st = self.ed = mid;
            return self;
        }
        if (lx.cnt == 1) {
            if (mid == rx.st + 1) {
                self.over = 0;
                self.st = rx.st + 1, self.ed = rx.ed;
            } else {
                self.over = 1;
                self.st = rx.st, self.ed = rx.ed;
            }
            return self;
        }
        if (rx.cnt == 1) {
            if (mid == lx.ed - 1) {
                self.over = lx.over;
                self.st = lx.st, self.ed = lx.ed - 1;
            } else {
                self.over = 1;
                self.st = self.ed = mid;
            }
            return self;
        }
        if (mid == lx.ed - 1 && mid == rx.st + 1) {
            self.over = lx.over;
            self.st = lx.st, self.ed = rx.ed;
        } else if (mid == rx.st + 1) {
            self.over = 1;
            self.st = rx.st + 1, self.ed = rx.ed;
        } else {
            self.over = 1;
            self.st = rx.st, self.ed = rx.ed;
        }
        return self;
    }

    inline void update(int i) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void build(int i, int l, int r) {
        if (l == r) {
            t[i].init(a[l]);
            return;
        }
        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        update(i);
    }

    void change(int i, int l, int r, int pos, int val) {
        if (l == r) {
            t[i].init(val);
            return;
        }
        int mid = l + r >> 1;
        if (mid >= pos) change(i << 1, l, mid, pos, val);
        else change(i << 1 | 1, mid + 1, r, pos, val);
        update(i);
    }

    Node query(int i, int l, int r, int st, int ed) {
        if (st <= l && r <= ed) return t[i];
        int mid = l + r >> 1;
        if (st <= mid && mid + 1 <= ed) return query(i << 1, l, mid, st, ed) + query(i << 1 | 1, mid + 1, r, st, ed);
        if (st <= mid) return query(i << 1, l, mid, st, ed);
        return query(i << 1 | 1, mid + 1, r, st, ed);
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c == '1';
    }
    Seg::build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            Seg::Node ans = Seg::query(1, 1, n, l, r);
            cout << ans.cal() << endl;
        } else {
            int pos;
            cin >> pos;
            a[pos] ^= 1;
            Seg::change(1, 1, n, pos, a[pos]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
