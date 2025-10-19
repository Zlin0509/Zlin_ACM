//
// Created by Zlin on 2025/10/19.
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

constexpr ll MOD = 998244353, G = 3;

ll qpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void ntt(vector<ll> &a, int n, int invert) {
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = qpow(G, (MOD - 1) / len);
        if (invert) wlen = qpow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        ll inv_n = qpow(n, MOD - 2);
        for (auto &x: a) x = x * inv_n % MOD;
    }
}

// 多项式乘法
vector<ll> multiply(vector<ll> A, vector<ll> B) {
    int n = 1;
    while (n < (int) A.size() + (int) B.size()) n <<= 1;
    A.resize(n);
    B.resize(n);

    ntt(A, n, 0);
    ntt(B, n, 0);
    for (int i = 0; i < n; i++) A[i] = A[i] * B[i] % MOD;
    ntt(A, n, 1);

    A.resize((int) A.size()); // 可以 trim 掉尾部 0
    return A;
}

int fx[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

constexpr int N = 4e5 + 10;

vll a, b;

int n, m;

ll val[N];

inline void Zlin() {
    cin >> n >> m;
    a.assign(m, 0);
    b.assign(m, 0);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < min(10, m); i++) b[i] = fx[i];
    for (int i = 10, j; i < m; i++) {
        j = i;
        while (j) {
            b[i] += fx[j % 10];
            j /= 10;
        }
    }
    reverse(a.begin(), a.end());
    auto res = multiply(a, b);
    for (int i = 0; i <= m * 2 - 2; i++) val[i % m] += res[i];
    ll ans = 0;
    for (int i = 0; i < m; i++) ans = max(ans, val[i]);
    cout << ans << endl;
    // for (const auto it: res) cout << it << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
