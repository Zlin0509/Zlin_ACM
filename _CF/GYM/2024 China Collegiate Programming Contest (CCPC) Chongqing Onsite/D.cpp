//
// Created by 27682 on 2025/9/15.
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

ll a, b, c, d;
ll fac2[60], fac5[50], C;

inline void Zlin(int t = 0) {
    cin >> a >> b;
    // a = t, b = 1e6 - 1;
    C = c = d = 2e9;
    for (int i = 0; fac2[i] <= b; i++) {
        for (int j = 0; fac2[i] * fac5[j] <= b; j++) {
            ll base = fac2[i] * fac5[j];
            if (b % base == 0) C = min(C, b / base);
        }
    }
    for (int i = 0; fac2[i] * b < 1e17; i++) {
        for (int j = 0; fac2[i] * fac5[j] * b < 1e17; j++) {
            ll cx = (C - fac2[i] * fac5[j] % C * a % C) % C, dx = b * fac2[i] * fac5[j];
            ll z = gcd(cx, dx);
            cx /= z, dx /= z;
            if (dx > 1e9) continue;
            if (cx < c) c = cx, d = dx;
            else if (cx == c) d = min(d, dx);
        }
    }
    if (d > 1e9) while (1);
    cout << c << ' ' << d << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    fac2[0] = fac5[0] = 1;
    for (int i = 1; i < 58; i++) fac2[i] = fac2[i - 1] * 2;
    for (int i = 1; i < 30; i++) fac5[i] = fac5[i - 1] * 5;
    cin >> ttt;
    while (ttt--) Zlin();
    // for (int i = 1; i < 1e6; i++) Zlin(i);
    return 0;
}
