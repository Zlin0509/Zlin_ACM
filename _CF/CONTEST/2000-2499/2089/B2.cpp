//
// Created by 27682 on 2025/5/7.
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

constexpr int N = 2e5 + 10;

int n, mx, a[N], b[N];
ll k, sum;

struct {
    ull val[3200];


    void init() {
        for (int i = 0; i <= mx; i++) val[i] = -1;
    }

    void change(int i) {
        val[i >> 6] ^= 1ull << (i & 63);
    }

    ull query(int i) {
        return val[i >> 6] >> (i & 63) & 1;
    }

    void move() {
        ull q = query(n - 1);
        for (int i = mx; i; i--) val[i] <<= 1, val[i] |= val[i - 1] >> 63;
        val[0] <<= 1, val[0] |= q;
    }
} ax, bx;

inline void Zlin() {
    cin >> n >> k;
    sum = 0;
    mx = n - 1 >> 6;
    ax.init(), bx.init();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (sum <= k) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    while (sum > k) {
        for (int i = 0; i <= mx; i++) {
            ull z = ax.val[i] & bx.val[i];
            if (z) {
                int pre = i << 6;
                for (int j = 0, lx, rx, t; j < 63 && pre + j < n; j++) {
                    if (z >> j & 1) {
                        rx = pre + j;
                        lx = (rx - ans + n) % n;
                        t = min(a[lx], b[rx]);
                        a[lx] -= t, b[rx] -= t, sum -= t;
                        if (!a[lx]) ax.change(rx);
                        if (!b[rx]) bx.change(rx);
                    }
                }
            }
        }
        ++ans;
        ax.move();
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
