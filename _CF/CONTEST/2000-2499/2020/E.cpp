//
// Created by 27682 on 2025/3/4.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 1e9 + 7;

inline ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1)
            res = res * x % mo;
        x = x * x % mo;
        y >>= 1;
    }
    return res;
}

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n), p(n);
    for (int &it: a)
        cin >> it;
    for (int &it: p)
        cin >> it;
    vll f(1024), g(1024);
    ll fac = qpow(10000, mo - 2) % mo;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1024; j++) {
            // 不拿
            g[j] = (g[j] + f[j] * (10000 - p[i]) % mo * fac % mo) % mo;
            // 拿
            g[j ^ a[i]] = (g[j ^ a[i]] + f[j] * p[i] % mo * fac % mo) % mo;
        }
        for (int j = 0; j < 1024; j++)
            f[j] = g[j], g[j] = 0;
    }
    ll ans = 0;
    for (int i = 0; i < 1024; i++)
        ans = (ans + i * i % mo * f[i] % mo) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}