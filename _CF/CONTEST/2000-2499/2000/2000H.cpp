//
// Created by Zlin on 2024/9/11.
//
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 4e6 + 5;

struct tree {
    int l, r;
    int lx, rx, mx;
    int tag;
} t[N << 2];
set<int> have;
int n, m, ans;

inline void pushup(int i) {
    if (t[i << 1].mx >= t[i << 1 | 1].mx) {
        t[i].tag = t[i << 1].tag;
        t[i].mx = t[i << 1].mx;
    } else {
        t[i].tag = t[i << 1 | 1].tag;
        t[i].mx = t[i << 1 | 1].mx;
    }
    if (t[i << 1].rx + t[i << 1 | 1].lx > t[i].mx) {
        t[i].tag = t[i << 1].r - t[i << 1].rx;
        t[i].mx = t[i << 1].rx + t[i << 1 | 1].lx;
    }
    if (!t[i].mx)
        t[i].tag = t[i].r;
    if (t[i].mx == t[i].r - t[i].l + 1) {
        t[i].lx = t[i].mx;
        t[i].rx = t[i].mx;
    } else if (t[i << 1].lx == t[i << 1].r - t[i << 1].l + 1) {
        t[i].lx = t[i << 1].lx + t[i << 1 | 1].lx;
        t[i].rx = t[i << 1 | 1].rx;
    } else if (t[i << 1 | 1].rx == t[i << 1 | 1].r - t[i << 1 | 1].l + 1) {
        t[i].lx = t[i << 1].lx;
        t[i].rx = t[i << 1 | 1].rx + t[i << 1].rx;
    } else{
        t[i].lx = t[i << 1].lx;
        t[i].rx = t[i << 1 | 1].rx;
    }
}

inline void build(int l, int r, int i) {
    if (l == r) {
        t[i] = {l, r, 1, 1, 1, l - 1};
        return;
    }
    t[i].l = l, t[i].r = r;
    int mid = l + r >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    pushup(i);
}

inline void ins(int x, int i) {
    if (t[i].l == t[i].r) {
        t[i].mx = t[i].lx = t[i].rx = 0;
        t[i].tag = t[i].l;
        return;
    }
    int mid = t[i].l + t[i].r >> 1;
    mid >= x ? ins(x, i << 1) : ins(x, i << 1 | 1);
    pushup(i);
}

inline void del(int x, int i) {
    if (t[i].l == t[i].r) {
        t[i].mx = t[i].lx = t[i].rx = 1;
        t[i].tag = t[i].l - 1;
        return;
    }
    int mid = t[i].l + t[i].r >> 1;
    mid >= x ? del(x, i << 1) : del(x, i << 1 | 1);
    pushup(i);
}

inline void query(int k, int i) {
    if (t[i].mx < k) return;
    if (t[i << 1].mx >= k) {
        ans = min(ans, t[i << 1].tag + 1);
        query(k, i << 1);
    } else if (t[i << 1].rx + t[i << 1 | 1].lx >= k) {
        ans = min(ans, t[i << 1].r - t[i << 1].rx + 1);
    } else if (t[i << 1 | 1].mx >= k) {
        ans = min(ans, t[i << 1 | 1].tag + 1);
        query(k, i << 1 | 1);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        ins(x, 1);
        have.insert(x);
    }
    char c;
    int x;
    cin >> m;
    while (m--) {
        cin >> c >> x;
        if (c == '+') {
            ins(x, 1);
            have.insert(x);
        } else if (c == '-') {
            del(x, 1);
            have.erase(have.find(x));
        } else {
            ans = 1e8;
            query(x, 1);
//            cout << t[place].l << ' ' << t[place].r << ' ';
            cout << ans << ' ';
        }
    }
    cout << '\n';

    for (auto it: have) del(it, 1);
    have.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    build(1, N - 5, 1);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}