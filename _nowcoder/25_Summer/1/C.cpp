//
// Created by 27682 on 2025/7/15.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr int N = 1010;

int n, q, d;
ll a[N], w[N];

struct Seg {
    struct node {
        int l, r;
        ll a, b;
    } t[N << 2];

    void build(int i, int l, int r) {
        t[i].l = l, t[i].r = r;
    }
} t;

vi have;

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], have.emplace_back(a[i]);
    for (int i = 1; i < n; i++) cin >> w[i];
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    t.build(1, 0, have.size() - 1);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
