//
// Created by 27682 on 2025/9/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr db EPS = 1e-7;
constexpr db PI = acos(-1);

inline void Zlin() {
    db a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    db u1 = x1 / a, v1 = y1 / b;
    db u2 = x2 / a, v2 = y2 / b;
    db vx = u2 - u1, vy = v2 - v1;
    db denom = hypotl(vx, vy);
    if (denom < EPS) {
        cout << "-1\n";
        return;
    }
    db cross = fabsl(u1 * vy - v1 * vx);
    db h = cross / denom;
    if (h > 1.0L + EPS) {
        cout << "-1\n";
        return;
    }
    if (fabsl(h - 1.0L) <= EPS) {
        cout << "-1\n";
        return;
    }
    if (h < 0) h = 0;
    db s = acosl(h) - h * sqrtl(max(0.0, 1.0 - h * h));
    db r = s / (PI - s);
    cout << fixed << setprecision(6) << r << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
