//
// Created by Zlin on 2024/10/19.
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
ll ans = 0;
ll n, k, m, c, d;
ll a[N];

struct Tree {
    int l, r;
    ll mx, mm, tag;
} t[N << 2];

// 建树
void build(int i, int l, int r) {
    if (l == r) {
        t[i].l = l, t[i].r = r;
        t[i].mx = t[i].mm = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    t[i].l = l, t[i].r = r;
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mm = min(t[i << 1].mm, t[i << 1 | 1].mm);
}

//更新懒标记
void pushdown(int i) {
    if (!t[i].tag) return;
    t[i].mx += t[i].tag;
    t[i].mm += t[i].tag;
    if (t[i].l != t[i].r) {
        t[i << 1].tag += t[i].tag;
        t[i << 1 | 1].tag += t[i].tag;
    }
    t[i].tag = 0;
}

//区间修改
void modify(int i, int l, int r, ll z) {
    if (t[i].l > r || t[i].r < l) return;
    pushdown(i);
    if (t[i].l >= l && t[i].r <= r) {
        t[i].tag += z;
        pushdown(i);
        return;
    }
    modify(i << 1, l, r, z);
    modify(i << 1 | 1, l, r, z);
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mm = min(t[i << 1].mm, t[i << 1 | 1].mm);
}

//区间查询
int query(int i, int l, int r, ll tag) {
    if (t[i].l > r || t[i].r < l || t[i].mx + t[i].tag < tag) return 0;
    pushdown(i);
    if (t[i].r <= r && t[i].l >= l && t[i].mm >= tag) return t[i].r - t[i].l + 1;
    return query(i << 1, l, r, tag) + query(i << 1 | 1, l, r, tag);
}

void cal() {
    ll l = 0, r = 1e9 + c + d * m, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (query(1, 1, n, mid) >= k) l = mid;
        else r = mid - 1;
    }
    ans = max(ans, l);
}

inline void Zlin() {
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 0; i < m; i++) modify(1, i + n - m + 1, i + n - m + 1, c + d * i);
    for (int i = n - m; i; i--) {
        cal();
        modify(1, i, i, c);
        modify(1, i + 1, i + m - 1, d);
        modify(1, i + m, i + m, -c - d * (m - 1));
    }
    cal();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}