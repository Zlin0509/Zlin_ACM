//
// Created by Zlin on 2025/8/8.
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

inline void Zlin() {
    ll K, N, A, B, C, D;
    ll xa, ya, xb, yb, la, lb, z;
    cin >> K >> N >> A >> B >> C >> D;
    ll base1 = K * D / (N * C), base2 = base1 + 1;

    la = K, lb = N * base2;
    z = gcd(la, lb);
    la /= z, lb /= z;

    if (la * B >= lb * A) xb = la * (1 + base2), yb = lb;
    else xb = 0, yb = 1;
    z = gcd(xb, yb);
    xb /= z, yb /= z;

    xa = C * (1 + base1), ya = D;
    z = gcd(xa, ya);
    xa /= z, ya /= z;

    if (xa * yb >= xb * ya) cout << xa << '/' << ya << endl;
    else cout << xb << '/' << yb << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
