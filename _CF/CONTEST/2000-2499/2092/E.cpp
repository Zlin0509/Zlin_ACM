//
// Created by Zlin on 2025/3/29.
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

constexpr ll mo = 1e9 + 7;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void Zlin() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll tot, free;
    tot = n * m;
    free = tot - k;

    int tag1 = 0, tag2 = 0;
    for (int i = 1, x, y, c; i <= k; i++) {
        cin >> x >> y >> c;
        bool check1 = (x == 1 || x == n || y == 1 || y == m);
        bool check2 = ((x == 1 && y == 1) || (x == 1 && y == m) ||
                       (x == n && y == 1) || (x == n && y == m));
        if (check1 && !check2) {
            tag1++;
            tag2 ^= c;
        }
    }

    ll tot1 = 2ll * (m + n - 4);
    ll free1 = tot1 - tag1;
    ll free2 = free - free1;

    ll ans = 0;
    if (!free1) {
        ans = tag2 == 0 ? qpow(2, free2) : 0;
    } else {
        ll x = qpow(2, free1 - 1);
        ll y = qpow(2, free2);
        ans = (x * y) % mo;
    }

    cout << ans % mo << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
