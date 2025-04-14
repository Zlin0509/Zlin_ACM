//
// Created by 27682 on 2025/4/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 1e9 + 7;
constexpr int N = 1e6;

ll fac[N + 10];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vll dp0(n + 1), dp1(n + 1);
    dp0[0] = dp1[0] = 1;
    dp0[1] = 21, dp1[1] = 5;
    for (int i = 2; i <= k; i++) {
        dp1[i] = (dp0[i - 1] + dp1[i - 1]) * 5 % mo;
        dp0[i] = (dp0[i - 1] + dp1[i - 1]) * 21 % mo;
    }
    ll val = 0, l = 1;
    for (int i = 1; i <= k; i++) val = (val + dp0[i] * fac[k - i + 1]) % mo;
    for (int i = k + 1; i <= n; i++) {
        dp1[i] = val;
        dp0[i] = (dp0[i - 1] + dp1[i - 1]) * 21 % mo;
        val = (val - fac[k] * dp0[l++] % mo + mo) % mo;
        val = (val + dp0[i]) * 5 % mo;
    }
    cout << (dp0[n] + dp1[n]) % mo << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * 5 % mo;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
