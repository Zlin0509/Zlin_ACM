//
// Created by Zlin on 2025/10/10.
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

constexpr int N = 2e5 + 5;

int n;
vi cx, cy;
vector<pii> in[N], out[N];

struct Node {
    int x1, y1, x2, y2;
} a[N];

struct T {
    ll val, tag;
} t[N << 2];

inline void build(int i, int l, int r) {
    t[i] = {0, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
}

inline void update(int i, int l, int r, int ql, int qr, int op) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) t[i].tag += op;
    else {
        int mid = l + r >> 1;
        update(i << 1, l, mid, ql, qr, op);
        update(i << 1 | 1, mid + 1, r, ql, qr, op);
    }
    if (t[i].tag) t[i].val = cx[r + 1] - cx[l];
    else {
        if (l == r) t[i].val = 0;
        else t[i].val = t[i << 1].val + t[i << 1 | 1].val;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        cx.emplace_back(a[i].x1);
        cy.emplace_back(a[i].y1);
        cx.emplace_back(a[i].x2);
        cy.emplace_back(a[i].y2);
    }
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    cx.erase(unique(cx.begin(), cx.end()), cx.end());
    cy.erase(unique(cy.begin(), cy.end()), cy.end());
    for (int i = 0; i < n; i++) {
        a[i].x1 = lower_bound(cx.begin(), cx.end(), a[i].x1) - cx.begin();
        a[i].y1 = lower_bound(cy.begin(), cy.end(), a[i].y1) - cy.begin();
        a[i].x2 = lower_bound(cx.begin(), cx.end(), a[i].x2) - cx.begin();
        a[i].y2 = lower_bound(cy.begin(), cy.end(), a[i].y2) - cy.begin();
    }
    for (int i = 0; i < n; i++) {
        in[a[i].y1].emplace_back(a[i].x1, a[i].x2);
        out[a[i].y2].emplace_back(a[i].x1, a[i].x2);
    }
    build(1, 0, cx.size());
    for (const auto &[l, r]: in[0]) update(1, 0, cx.size(), l, r - 1, 1);
    for (const auto &[l, r]: out[0]) update(1, 0, cx.size(), l, r - 1, -1);
    ll ans = 0;
    for (int i = 1; i < cy.size(); i++) {
        ans += t[1].val * (cy[i] - cy[i - 1]);
        for (const auto &[l, r]: in[i]) update(1, 0, cx.size(), l, r - 1, 1);
        for (const auto &[l, r]: out[i]) update(1, 0, cx.size(), l, r - 1, -1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
