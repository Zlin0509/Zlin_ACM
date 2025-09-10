//
// Created by 27682 on 2025/9/9.
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

constexpr int N = 2e5 + 10;

int tot;
int rt[N << 5], ls[N << 5], rs[N << 5];

struct Seg {
    int vs, vl, vr;
} val[N << 5];

inline int add() {
    ++tot;
    val[tot] = {0, 0, 0};
    rt[tot] = ls[tot] = rs[tot] = 0;
    return tot;
}

inline Seg operator+(const Seg &a, const Seg &b) {
    Seg res;
    res.vs = a.vs + b.vs;
    res.vl = max(a.vl, a.vs + b.vl);
    res.vr = max(b.vr, a.vr + b.vs);
    return res;
}

inline void pushup(int i) {
    val[i] = val[ls[i]] + val[rs[i]];
}

inline int build(int l, int r) {
    int root = add();
    if (l == r) {
        val[root] = {-1, -1, -1};
        return root;
    }
    int mid = l + r >> 1;
    ls[root] = build(l, mid);
    rs[root] = build(mid + 1, r);
    pushup(root);
    return root;
}

inline int update(int k, int l, int r, int root) {
    int dir = add();
    if (l == r) {
        val[dir] = {1, 1, 1};
        return dir;
    }
    ls[dir] = ls[root], rs[dir] = rs[root];
    int mid = l + r >> 1;
    if (k <= mid) ls[dir] = update(k, l, mid, ls[dir]);
    else rs[dir] = update(k, mid + 1, r, rs[dir]);
    pushup(dir);
    return dir;
}

inline Seg query(int k, int l, int r, int L, int R) {
    if (!k) return {0, 0, 0};
    if (l <= L && r >= R) return val[k];
    int mid = L + R >> 1;
    if (r <= mid) return query(ls[k], l, r, L, mid);
    if (mid < l) return query(rs[k], l, r, mid + 1, R);
    return query(ls[k], l, r, L, mid) + query(rs[k], l, r, mid + 1, R);
}

int n, a[N];
int t[N], lx[N], rx[N];
vi stk;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], t[i] = i;
    sort(t + 1, t + 1 + n, [&](int x, int y) { return a[x] > a[y]; });
    tot = 0, rt[0] = build(1, n);
    for (int i = 1; i <= n; i++) rt[i] = update(t[i], 1, n, rt[i - 1]);
    stk.clear();
    for (int i = 1; i <= n; i++) lx[i] = 0, rx[i] = n + 1;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.back()] > a[i]) rx[stk.back()] = i, stk.pop_back();
        if (!stk.empty()) lx[i] = stk.back();
        stk.emplace_back(i);
    }
    int ans = 0;
    for (int i = 1, l, r, mid, res; i <= n; i++) {
        l = 1, r = n;
        while (l < r) {
            mid = l + r >> 1, res = 0;
            res += query(rt[mid], lx[i] + 1, i, 1, n).vr;
            res += query(rt[mid], i, rx[i] - 1, 1, n).vl;
            res -= query(rt[mid], i, i, 1, n).vs;
            if (res >= 0) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, a[t[l]] - a[i]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
