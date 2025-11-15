//
// Created by Zlin on 2025/11/15.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    db x, y, vx, vy;
    db ly, ry, vly, vry;
    db lx, rx, vlx, vrx;
    db X, Y, t, tmp;
    cin >> x >> y >> vx >> vy;
    cin >> ly >> ry >> vly >> vry;
    cin >> lx >> rx >> vlx >> vrx;
    t = (ry - ly) / (vry + vly);
    Y = ly + t * vly;
    X = x;
    int op = vx > 0 ? 1 : 0;
    vx = abs(vx);
    if (vlx == 0 && vrx == 0) {
        if (op) tmp = (rx - X) / vx;
        else tmp = (X - lx) / vx;
        if (tmp >= t) {
            if (op) X += vx * t;
            else X -= vx * t;
            cout << fixed << setprecision(12) << X << " " << Y << endl;
            return;
        }
        t -= tmp;
        if (op) X = rx;
        else X = lx;
        op ^= 1;
        db dif = (rx - lx) / vx;
        int lss = 0, rss = 1e9, mid;
        while (lss < rss) {
            mid = (lss + rss + 1) / 2;
            if (dif * 2 * mid <= t) lss = mid;
            else rss = mid - 1;
        }
        t -= dif * 2 * lss;
        if (t >= dif) {
            t -= dif;
            if (op) X = rx;
            else X = lx;
            op ^= 1;
        }
        if (op) X += vx * t;
        else X -= vx * t;
        cout << fixed << setprecision(12) << X << " " << Y << endl;
        return;
    }
    while (true) {
        if (op) {
            if (vrx >= vx) {
                X += t * vx;
                break;
            }
            tmp = (rx - X) / (vx - vrx);
        } else {
            if (vlx >= vx) {
                X -= t * vx;
                break;
            }
            tmp = (X - lx) / (vx - vlx);
        }
        if (tmp >= t) {
            if (op) X += t * vx;
            else X -= t * vx;
            break;
        }
        t -= tmp;
        lx -= tmp * vlx;
        rx += tmp * vrx;
        if (op) X += tmp * vx;
        else X -= tmp * vx;
        op ^= 1;
    }
    cout << fixed << setprecision(12) << X << " " << Y << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
