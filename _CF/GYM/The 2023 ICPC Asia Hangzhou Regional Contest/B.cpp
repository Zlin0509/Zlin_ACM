//
// Created by 27682 on 2025/10/29.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef __int128 i128;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 250001;
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

int n, q;
ll x[N], c[N], ans[N];

inline void Zlin() {
    cin >> n >> q;
    vll a(N), b(N);
    for (int i = 1; i <= n; i++) cin >> x[i] >> c[i];
    int l = 1, r = 3;
    while (l <= n) {
        vll res(N), tmp;

        // A * B
        a.assign(N, 0);
        b.assign(N, 0);
        for (int i = 1; i <= n; i++) {
            b[x[i]] = c[i];
            if (i >= l && i < r) a[x[i]] = c[i];
        }
        reverse(a.begin(), a.end());
        tmp = multiply(a, b);
        for (int i = N - 1; i <= N * 2 - 2; i++) res[i - (N - 1)] -= 2 * tmp[i];

        // A ^ 2
        a.assign(N, 0);
        b.assign(N, 0);
        for (int i = 1; i <= n; i++) {
            b[x[i]] = 1;
            if (i >= l && i < r) a[x[i]] = c[i] * c[i];
        }
        reverse(a.begin(), a.end());
        tmp = multiply(a, b);
        for (int i = N - 1; i <= N * 2 - 2; i++) res[i - (N - 1)] += tmp[i];

        // B ^ 2
        a.assign(N, 0);
        b.assign(N, 0);
        for (int i = 1; i <= n; i++) {
            b[x[i]] = c[i] * c[i];
            if (i >= l && i < r) a[x[i]] = 1;
        }
        reverse(a.begin(), a.end());
        tmp = multiply(a, b);
        for (int i = N - 1; i <= N * 2 - 2; i++) res[i - (N - 1)] += tmp[i];
        for (int i = 1; i < N; i++) if (res[i] && !ans[i]) ans[i] = 1.5 * l;
        l = r, r = l * 3;
    }
    while (q--) {
        int d;
        cin >> d;
        cout << ans[d] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
