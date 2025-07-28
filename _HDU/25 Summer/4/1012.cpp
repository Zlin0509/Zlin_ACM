//
// Created by Zlin on 2025/7/28.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ldb eps = 1E-9;

ldb ans;
ll n, m, sx, sy;
ll a[6], h[7], w[7];

void output(long double x) {
    static char s[25];
    sprintf(s, "%.4Le", x);
    for (int i: {0, 1, 2, 3, 4, 5, 6, 7}) printf("%c", s[i]);
    printf("%c", s[strlen(s) - 1]);
}

// 定义函数 y = f(x)
ldb f(ldb x) {
    ldb res = 0;
    for (int i = 5; ~i; i--) res = res * x + a[i];
    return res;
}

// f'(x)
ldb df(ldb x) {
    ldb res = 0;
    for (int i = 5; i; i--) res = res * x + i * a[i];
    return res;
}

// sqrt(1 + f'(x)^2)
ldb g(ldb x) {
    ldb d = df(x);
    return sqrtl(1 + d * d);
}

// 单区间辛普森积分
ldb sim(ldb l, ldb r) {
    ldb m = (l + r) / 2;
    return (g(l) + 4 * g(m) + g(r)) * (r - l) / 6;
}

// 自适应辛普森积分
ldb ads(ldb l, ldb r, ldb e, ldb s) {
    ldb m = (l + r) / 2;
    ldb sl = sim(l, m);
    ldb sr = sim(m, r);
    if (fabsl(sl + sr - s) <= 15 * e) return sl + sr + (sl + sr - s) / 15;
    return ads(l, m, e / 2, sl) + ads(m, r, e / 2, sr);
}

// 计算弧长
ldb arc(ldb a, ldb b, ldb e = 1e-9) {
    return ads(a, b, e, sim(a, b));
}

ldb ax, bx;

inline ldb dis(ldb x, ldb y, ldb ax, ldb ay) {
    return sqrtl((ax - x) * (ax - x) + (ay - y) * (ay - y));
}

inline ldb find_nxt(ldb lx, ldb h1, ldb h2) {
    ldb l = lx, r = 1e18, mid, ly = f(lx) + h1;
    ldb k = (ly - sy) / (lx - sx), b = -k * lx + ly;
    while (r - l >= eps) {
        mid = (l + r) / 2;
        ldb my = f(mid);
        if (dis(mid, my, lx, ly - h1) < max(h1, h2) || k * mid + b > my) l = mid;
        else r = mid;
    }
    return l;
}

inline void Zlin() {
    cin >> n >> m >> sx >> sy;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = m + 1; i <= 5; i++) a[i] = 0;
    for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
    ans = 1e18;
    vi base(n);
    iota(base.begin(), base.end(), 0);
    do {
        ldb res = 0, x = 0, sum = 0, lst = 0;
        for (int i = 0; i < n; i++) {
            sum += arc(lst, x);
            res += sum * w[base[i]];
            if (i == n - 1) break;
            lst = x;
            x = find_nxt(x, h[base[i]], h[base[i + 1]]);
        }
        ans = min(ans, res);
    } while (next_permutation(base.begin(), base.end()));
    output(ans);
    printf("\n");
}

signed main() {
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
