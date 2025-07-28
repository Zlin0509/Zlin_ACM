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
int n, m, sx, sy;
int a[6], h[7], w[7], vis[7];

void output(long double x) {
    static char s[25];
    sprintf(s, "%.4Le", x);
    for (int i: {0, 1, 2, 3, 4, 5, 6, 7}) printf("%c", s[i]);
    printf("%c", s[strlen(s) - 1]);
}

db f(db x) {
    db res = 0;
    for (int i = 1; i <= 5; i++) res += 1.0 * a[i] * pow(x, i);
    return res;
}

db df(db x) {
    db res = 0;
    for (int i = 1; i <= 5; i++) {
        res += i * a[i] * pow(x, i - 1);
    }
    return res;
}

db F(db x) {
    db dfx = df(x);
    return sqrt(1 + dfx * dfx);
}

db simpson(db l, db r) {
    db mid = (l + r) / 2;
    return (F(l) + 4 * F(mid) + F(r)) * (r - l) / 6;
}

db adaptive_simpson(db l, db r, db eps, db whole) {
    db mid = (l + r) / 2;
    db left = simpson(l, mid), right = simpson(mid, r);
    if (fabs(left + right - whole) <= 15 * eps)
        return left + right + (left + right - whole) / 15.0;
    return adaptive_simpson(l, mid, eps / 2, left) + adaptive_simpson(mid, r, eps / 2, right);
}

db arc_length(db l, db r) {
    return adaptive_simpson(l, r, eps, simpson(l, r));
}

ldb ax, bx;

inline ldb fx(ldb x) {
    return ax * x + bx;
}

inline ldb dis(ldb x, ldb y, ldb ax, ldb ay) {
    return (ax - x) * (ax - x) + (ay - y) * (ay - y);
}

inline ldb find_nxt(ldb lx, ldb tag) {
    ldb l = lx, r = 1e18, mid;
    while (abs(r - l) >= eps) {
        mid = (l + r) / 2;
        if (dis(mid, f(mid), lx, f(lx)) >= tag) r = mid;
        else l = mid;
    }
    r = 1e18;
    while (abs(r - l) >= eps) {
        mid = (l + r) / 2;
        if (f(mid) > fx(mid)) r = mid;
        else l = mid;
    }
    return l;
}


inline void dfs(int dep, vi &base) {
    if (dep == n) {
        ldb res = 0;
        ldb x = 0, y = 0;
        for (int i = 0; i < dep - 1; i++) {
            res += arc_length(0, x) * w[base[i]];
            y = f(x) + h[base[i]];
            ax = 1.0 * (sy - y) / (sx - x);
            bx = y - x * (sy - y) / (sx - x);
            x = find_nxt(x, max(h[base[i]] * h[base[i]], h[base[i + 1]] * h[base[i + 1]]));
        }
        res += arc_length(0, x) * w[base[dep - 1]];
        ans = min(ans, res);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            base.emplace_back(i);
            dfs(dep + 1, base);
            base.pop_back();
            vis[i] = 0;
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> sx >> sy;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = m + 1; i <= 5; i++) a[i] = 0;
    for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
    ans = 1e18;
    vi base;
    dfs(0, base);
    output(ans);
    cout << endl;
}

signed main() {
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
