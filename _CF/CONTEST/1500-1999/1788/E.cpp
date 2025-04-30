//
// Created by 27682 on 2025/4/22.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;
constexpr int inf = 1e9;

int n, nx;
vi f;
vll a, sum;

struct node {
    int l, r, val;
} t[N << 2];

inline void pushup(int i) { t[i].val = max(t[i << 1].val, t[i << 1 | 1].val); }

inline void build(int i, int l, int r) {
    t[i].l = l, t[i].r = r;
    if (l == r) {
        t[i].val = -inf;
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    pushup(i);
}

inline void modify(int i, int id, int val) {
    if (t[i].l > id || t[i].r < id) return;
    if (t[i].l == t[i].r) {
        t[i].val = max(t[i].val, val);
        return;
    }
    modify(i << 1, id, val);
    modify(i << 1 | 1, id, val);
    pushup(i);
}

inline int query(int i, int l, int r) {
    if (t[i].l > r || t[i].r < l) return -inf;
    if (t[i].l >= l && t[i].r <= r) return t[i].val;
    return max(query(i << 1, l, r), query(i << 1 | 1, l, r));
}

inline void Zlin() {
    cin >> n;
    a.assign(n + 1, 0);
    f.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    a = sum;
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(sum.begin(), sum.end(), a[i]) - sum.begin();
    nx = sum.size();
    build(1, 0, nx - 1);
    for (int i = 1; i <= n; i++) {
        if (sum[a[i]] >= 0) {
            f[i] = i;
        } else {
            f[i] = f[i - 1];
            if (i > 1 && sum[a[i]] - sum[a[i - 1]] >= 0) ++f[i];
            f[i] = max(f[i], i + query(1, 0, a[i]));
        }
        modify(1, a[i], f[i] - i);
    }
    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
