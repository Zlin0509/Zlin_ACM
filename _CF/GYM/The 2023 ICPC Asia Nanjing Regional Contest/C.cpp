//
// Created by Zlin on 2024/10/13.
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

ll p, m, l, r;

inline void Zlin() {
    cin >> p >> m;
    l = p, r = p;
    int len = 0;
    while ((1ll << len) <= m) ++len;
    --len;
    ll z = m;
    while (~len) {
        if (((1ll << len) & l) && ((1ll << len) <= z)) {
            l -= (1ll << len);
            z -= (1ll << len);
        }
        --len;
    }
    len = 0;
    while ((1ll << len) <= m) ++len;
    --len;
    z = m;
    while (~len) {
        if (!((1ll << len) & r) && ((1ll << len) <= z)) {
            r += (1ll << len);
            z -= (1ll << len);
        }
        --len;
    }
//    cout << l << ' ' << r << '\n';
    ll lx;
    if (l - 1 >= p) {
        lx = (l - 1) / p;
        if ((l - 1) % p) ++lx;
    } else lx = 0;
    ll rx = (r - 1) / p;
    ll ans = rx - lx + 1;
//    cout << lx << ' ' << rx << '\n';
    for (ll i = rx; i >= max(rx - 500, lx); i--)
        if (((i * p + 1ll) ^ (p - 1ll)) > m) --ans;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 100;
    cin >> ttt;
    while (ttt--) Zlin();
}