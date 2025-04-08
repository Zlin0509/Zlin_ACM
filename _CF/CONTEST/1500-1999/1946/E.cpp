//
// Created by Zlin on 2025/4/8.
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
constexpr int N = 2e5;

ll fac[N + 10], inv[N + 10];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void dd() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[N] = qpow(fac[N], mo - 2);
    for (int i = N - 1; i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

inline ll comb(int n, int k) {
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}


inline void Zlin() {
    int n, ml, mr;
    cin >> n >> ml >> mr;
    vi lx(ml), rx(mr);
    for (int &it: lx) cin >> it;
    for (int &it: rx) cin >> it;
    if (lx[ml - 1] != rx[0] || lx[0] != 1 || rx[mr - 1] != n) {
        cout << 0 << endl;
        return;
    }
    ll ans = comb(n - 1, rx[0] - 1);
    for (int i = ml - 2; ~i; i--) {
        ans = ans * fac[lx[i + 1] - lx[i] - 1] % mo;
        ans = ans * comb(lx[i + 1] - 2, lx[i + 1] - lx[i] - 1) % mo;
    }
    for (int i = 1; i < mr; i++) {
        ans = ans * fac[rx[i] - rx[i - 1] - 1] % mo;
        ans = ans * comb(n - rx[i - 1] - 1, rx[i] - rx[i - 1] - 1) % mo;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
