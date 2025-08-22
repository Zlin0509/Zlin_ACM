//
// Created by Zlin on 2025/8/22.
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

constexpr int dx[6]{1, 0, -1, -1, 0, 1}, dy[6]{1, 1, 0, -1, -1, 0};

struct Eq2 {
    ll a, b, c, d, e, f;
    // 方程组:
    // a * x + b * y = c
    // d * x + e * y = f

    Eq2(ll _a, ll _b, ll _c, ll _d, ll _e, ll _f) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        e = _e;
        f = _f;
    }

    struct Ans {
        bool ok, inf; // ok=1 有解, inf=1 无穷多解
        ll x, y;
    };

    Ans solve() {
        Ans s{0, 0, 0, 0};
        ll D = a * e - b * d;
        ll Dx = c * e - b * f;
        ll Dy = a * f - c * d;

        if (D == 0) {
            if (Dx == 0 && Dy == 0) {
                // 无限解
                s.inf = true;
            } else {
                // 无解
                s.ok = false;
            }
        } else {
            if (Dx % D != 0 || Dy % D != 0) {
                s.ok = false; // 解不是整数
            } else {
                s.ok = true;
                s.x = Dx / D;
                s.y = Dy / D;
            }
        }
        return s;
    }
};

int x, y;
int c[6], mm[6];

inline void Zlin() {
    cin >> x >> y;
    for (int i = 0; i < 6; i++) cin >> c[i];
    for (int i = 0; i < 6; i++) mm[i] = min(c[i], c[(i + 1) % 6] + c[(i + 5) % 6]);
    ll ans = 2e18;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            Eq2 res(dx[i], dx[j], x, dy[i], dy[j], y);
            auto r = res.solve();
            if (r.ok == 1 && r.x >= 0 && r.y >= 0) ans = min(ans, mm[i] * r.x + mm[j] * r.y);
            if (r.inf == 1) {
                int k = abs(x);
                if (dx[i] * k == x && dy[j] * k == y) ans = min(ans, 1ll * mm[i] * k);
                if (dx[j] * k == x && dy[j] * k == y) ans = min(ans, 1ll * mm[j] * k);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
