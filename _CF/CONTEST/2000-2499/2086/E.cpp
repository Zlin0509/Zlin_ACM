//
// Created by 27682 on 2025/9/10.
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

ll l, r, k;
ll val[32], dif[32], cnt[32], lx[32], rx[32];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

inline void Zlin() {
    cin >> l >> r >> k;
    for (int i = 31; i; i--) {
        ll z = max(0ll, k - dif[i - 1]);
        cnt[i] = z, k -= z;
    }
    for (int i = 1; i < 32; i++) cout << cnt[i] << ' ';
    ll tag = k;
    for (int i = 31; i && tag; i--) {
        ll k = min(tag, r / val[i]);
        rx[i] = k;
        r -= k * val[i];
        tag -= k;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    val[1] = 1, dif[0] = 0;
    for (int i = 2; i < 32; i++) val[i] = val[i - 1] + (1ll << 2 * i - 1);
    for (int i = 1; i < 32; i++) dif[i] = qpow(2, 2 * i) + 1;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}