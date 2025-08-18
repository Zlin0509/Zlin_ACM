//
// Created by Zlin on 2025/8/18.
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

constexpr int N = 2e5 + 5;
constexpr int MOD = 998244353; // 质数模数 p
constexpr int G = 3; // 原根 g

// 快速幂计算 a^b % mod
inline int mod_pow(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return res;
}

// NTT 核心函数
void ntt(vi &a, int n, int inv) {
    // 二进制反转置换
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }

    // 进行 NTT
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = inv == 1
                       ? mod_pow(G, (MOD - 1) / len, MOD)
                       : mod_pow(mod_pow(G, (MOD - 1) / len, MOD), MOD - 2, MOD);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = 1LL * a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = 1LL * w * wlen % MOD;
            }
        }
    }

    // 如果是逆变换，需要除以 n (即乘以 n 的逆元)
    if (inv == -1) {
        ll n_inv = mod_pow(n, MOD - 2, MOD);
        for (int &x: a) x = 1LL * x * n_inv % MOD;
    }
}

// 多项式乘法
vi poly_mult(const vi &a, const vi &b, const int &m) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    vi A(a.begin(), a.end()), B(b.begin(), b.end());
    A.resize(n);
    B.resize(n);

    ntt(A, n, 1);
    ntt(B, n, 1);

    for (int i = 0; i < n; i++) A[i] = 1LL * A[i] * B[i] % MOD;

    ntt(A, n, -1);

    for (int i = m; i < A.size(); i++) {
        A[i - m] = A[i];
        A[i] = 0;
    }

    while (!A.empty() && A.back() == 0) A.pop_back();

    return A;
}

int n, m;
vi ans, tmp;

inline void Zlin() {
    cin >> n >> m;
    ans.assign(1, 0);
    tmp.assign(m * 2 + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
        fill(tmp.begin(), tmp.end(), 0);
        for (int j = 0; j < m * 2 + 1; j++) cin >> tmp[j];
        ans = poly_mult(ans, tmp, m);
        ll res = 0;
        for (int it: ans) res = (res + it) % MOD;
        cout << res << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
