//
// Created by Zlin on 2024/9/12.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
int n, m;
vi e[N];
struct node {
    int l, r, cnt, lazy;
} t[N << 3];

struct ss {
    int l, r;
} a[N];

inline void build(int l, int r, int i) {
    if (l == r) {
        t[i].l = l, t[i].r = r;
        t[i].cnt = t[i].lazy = 0;
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    t[i].l = l, t[i].r = r;
    t[i].cnt = t[i].lazy = 0;
}

inline void pushup(int i) {
    if (t[i].lazy)
        t[i].cnt = t[i].r - t[i].l + 1;
    else
        t[i].cnt = t[i << 1].cnt + t[i << 1 | 1].cnt;
}

inline void change(int l, int r, int i, int k) {
    if (t[i].l > r || t[i].r < l) return;
    if (t[i].l >= l && t[i].r <= r) {
        t[i].lazy += k;
        pushup(i);
        return;
    }
    change(l, r, i << 1, k);
    change(l, r, i << 1 | 1, k);
    pushup(i);
}

inline int query(int l, int r, int i) {
    if (t[i].l > r || t[i].r < l) return 0;
    if (t[i].l >= l && t[i].r <= r) return t[i].cnt;
    return query(l, r, i << 1) + query(l, r, i << 1 | 1);
}

inline void Zlin() {
    cin >> n >> m;
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r;
    int ans = 1e9;
    for (int i = 1; i <= m; i++) {
        change(a[i].l + 1, a[i].r, 1, 1);
        e[a[i].l].push_back(a[i].r);
    }
    for (int l = 1, cnt; l <= n; l++) {
        ans = min(ans, query(1, n, 1));
        for (auto r: e[l]) {
            if (r > l) {
                e[r].push_back(l);
                change(l + 1, r, 1, -1);

                change(1, l, 1, 1);
                if (r != n)
                    change(r + 1, n, 1, 1);
            } else {
                change(1, r, 1, -1);
                if (l != n)
                    change(l + 1, n, 1, -1);

                change(r + 1, l, 1, 1);
            }
        }
    }
    ans = min(ans, query(1, n, 1));
    cout << ans << '\n';
    build(1, n, 1);
    for (int i = 1; i <= n; i++) e[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}