//
// Created by Zlin on 2025/9/29.
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

int cnt[2][10];

inline void Zlin() {
    ll p, q;
    cin >> p >> q;
    // p = q = 2e18;
    ll x = p, y = q, z = gcd(x, y), pp = p, qq = q;
    p /= z, q /= z;
    for (int t = 0; t < 1 << 19; t++) {
        ll fac = 1, i = 0, px = pp, qx = qq;
        ll lx = 0;
        memset(cnt, 0, sizeof(cnt));
        while (px) {
            if (t >> i & 1) {
                lx += px % 10 * fac;
                fac *= 10;
            } else cnt[0][px % 10]++;
            px /= 10;
            ++i;
        }
        if (lx % p == 0 && lx && lx < x) {
            ll rx = lx / p * q, cnt0 = 0;
            while (qx) {
                if (qx % 10 == rx % 10) {
                    if (rx) rx /= 10;
                    else ++cnt0;
                } else cnt[1][qx % 10]++;
                qx /= 10;
            }
            bool check = !rx;
            if (cnt[0][0] > cnt[1][0] + cnt0 || cnt[0][0] < cnt[1][0]) check = false;
            for (i = 1; i < 10; i++) if (cnt[0][i] != cnt[1][i]) check = false;
            if (check) x = lx, y = lx / p * q;
        }
    }
    cout << x << ' ' << y << endl;
}

/*

1
163 326

 */

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
