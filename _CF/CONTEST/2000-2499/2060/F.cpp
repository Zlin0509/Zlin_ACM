//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int long long
using namespace std;

typedef int i32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<i32> vi;
typedef vector<i64> vll;
typedef pair<i32, i32> pii;
typedef pair<i64, i64> pll;

constexpr i32 N = 2e5 + 10;
constexpr i64 mo = 998244353;

i64 fa[N], in[N];
i64 f[200][N];

inline i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void dd() {
    fa[0] = in[0] = 1;
    for (int i = 1; i < N; i++)
        fa[i] = fa[i - 1] * i % mo;
    in[N - 1] = qpow(fa[N - 1], mo - 2);
    for (int i = N - 2; i; i--)
        in[i] = in[i + 1] * (i + 1) % mo;
    for (int i = 2; i < N; i++)
        f[1][i] = 1;
    for (int i = 1; i < 40; i++) {
        for (int j = 2; j < N; j++) {
            for (int q = 2; q * j < N; q++) {
                f[i + 1][j * q] = (f[i + 1][j * q] + f[i][j]) % mo;
            }
        }
    }
}

i64 comb_large_n(i64 n, i64 k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k; // 利用对称性 C(n, k) = C(n, n-k)

    i64 res = 1, denom = 1;
    for (i64 i = 0; i < k; i++) {
        res = res * (n - i) % mo;
        denom = denom * (i + 1) % mo;
    }
    return res * qpow(denom, mo - 2) % mo; // 乘法逆元
}

inline void Zlin() {
    i32 k, n;
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        if (i == 1) {
            cout << n << ' ';
            continue;
        }
        i64 ans = 0;
        for (int len = 1; len <= min(30ll, n); len++)
            ans = (ans + f[len][i] * comb_large_n(n + 1, len + 1)) % mo;
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    i32 ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
