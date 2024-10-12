//
// Created by Zlin on 2024/10/12.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 10;

int n, q;
int a[N], x[N], v[N];
ll sum = 0;
map<int, int> id, val;

struct tree {
    int l, r, siz;
    ll val;
} t[N << 3];

inline void build(int i, int l, int r) {
    t[i].l = l, t[i].r = r;
    t[i].val = t[i].siz = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}

inline void change(int p, int i, int tag) {
    if (t[i].l > p || t[i].r < p) return;
    if (t[i].l == t[i].r) {
        t[i].siz += tag;
        t[i].val += tag * val[p];
        return;
    }
    change(p, i << 1, tag);
    change(p, i << 1 | 1, tag);
    t[i].siz = t[i << 1].siz + t[i << 1 | 1].siz;
    t[i].val = t[i << 1].val + t[i << 1 | 1].val;
}

inline ll query(int i, int cnt) {
    if (cnt <= 0 || !t[i].siz) return 0;
    if (t[i].l == t[i].r)
        return 1ll * val[t[i].l] * min(cnt, t[i].siz);
    if (t[i].siz <= cnt)
        return t[i].val;
    return query(i << 1, cnt) + query(i << 1 | 1, cnt - t[i << 1].siz);
}

inline bool check(int cnt) {
    return query(1, cnt) <= sum;
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> x[i] >> v[i];

    vi b;
    for (int i = 1; i <= n; i++)
        if (a[i] > 0)
            b.push_back(a[i]);
    for (int i = 1; i <= q; i++)
        if (v[i] > 0)
            b.push_back(v[i]);

    if (b.empty()) {
        for (int i = 1; i <= q; i++) cout << 1 << '\n';
        return;
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < b.size(); i++) {
        id[b[i]] = i + 1;
        val[i + 1] = b[i];
    }
    int cnt = 0;
    build(1, 1, b.size());
    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0) {
            sum -= a[i];
        } else {
            ++cnt;
            change(id[a[i]], 1, 1);
        }
    }

    for (int i = 1; i <= q; i++) {
        if (a[x[i]] <= 0) {
            sum += a[x[i]];
            if (v[i] <= 0) {
                sum -= v[i];
            } else {
                ++cnt;
                change(id[v[i]], 1, 1);
            }
        } else {
            --cnt;
            change(id[a[x[i]]], 1, -1);
            if (v[i] <= 0) {
                sum -= v[i];
            } else {
                ++cnt;
                change(id[v[i]], 1, 1);
            }
        }
        a[x[i]] = v[i];
        int l = 0, r = cnt, mid;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}