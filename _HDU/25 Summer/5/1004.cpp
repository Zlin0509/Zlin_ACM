//
// Created by Zlin on 2025/8/1.
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

constexpr int N = 1e5 + 10;
constexpr ll mo = 1e9 + 7;

int n, m, q[N], k[N];
ll fac[N];

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
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < m; i++) cin >> k[i];
    cout << qpow(fac[n], m) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mo;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
