//
// Created by Zlin on 2025/4/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll f[201], g[201];

inline void Zlin() {
    int x;
    cin >> x;
    if (x <= 200) {
        cout << f[x] << endl;
    } else {
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1, n = 200;
    f[0] = 1, g[0] = 0;
    ll inv = qpow(2, mo - 2);
    for (int i = 1; i <= 4; i++) {
        if (i < 4) {
            // 直接判负或者继续下去
            f[i] = (g[i - 1] * inv % mo + inv) % mo;
        } else {
            f[i] = (g[i - 1] * inv % mo + g[i - 4] * inv % mo) % mo;
        }
        g[i] = f[i - 1];
    }
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
