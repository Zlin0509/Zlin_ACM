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

inline void Zlin() {
    cin >> a >> b;
    C = b;
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 10; j++) {
            ll base = fac2[i] * fac5[j];
            if (b % base == 0) C = min(C, b / base);
        }
    }
    c = d = 1e9;
    for (int i = 0; fac2[i] * b < 1e16; i++) {
        for (int j = 0; fac2[i] * fac2[j] * b < 1e16; j++) {
            ll cx = (C - fac2[i] * fac5[j] % C * a % C) % C, dx = b * fac2[i] * fac5[j];
            ll z = gcd(cx, dx);
            cx /= z, dx /= z;
            if (dx > 1e9) continue;
            if (cx < c) c = cx, d = dx;
            else if (cx == c) d = min(d, dx);
        }
    }
    if (c == 1e9 || d == 1e9) while (1);
    cout << c << ' ' << d << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    fac2[0] = fac5[0] = 1;
    for (int i = 1; i < 55; i++) fac2[i] = fac2[i - 1] * 2;
    for (int i = 1; i < 35; i++) fac5[i] = fac5[i - 1] * 5;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
