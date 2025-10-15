//
// Created by Zlin on 2025/10/15.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef __int128 i128;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 5;

constexpr ll MOD = 180143985094819841; // 2^48 * 641 + 1
constexpr ll G = 6; // 原根

// 快速幂
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (i128) res * a % MOD;
        a = (i128) a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 原地 NTT, on = 1 为 DFT, on = -1 为 IDFT
void ntt(vector<ll> &a, int on) {
    int n = a.size();
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }

    for (int m = 2; m <= n; m <<= 1) {
        ll wn = qpow(G, (MOD - 1) / m);
        if (on == -1) wn = qpow(wn, MOD - 2);
        for (int k = 0; k < n; k += m) {
            ll w = 1;
            for (int j = 0; j < m / 2; j++) {
                ll x = a[k + j];
                ll y = (i128) a[k + j + m / 2] * w % MOD;
                a[k + j] = (x + y) % MOD;
                a[k + j + m / 2] = (x - y + MOD) % MOD;
                w = (i128) w * wn % MOD;
            }
        }
    }
    if (on == -1) {
        ll inv_n = qpow(n, MOD - 2);
        for (auto &x: a) x = (i128) x * inv_n % MOD;
    }
}

// 多项式乘法：C = A * B (mod MOD)
vector<ll> multiply(const vector<ll> &A, const vector<ll> &B) {
    int n = 1;
    while (n < (int) A.size() + (int) B.size() - 1) n <<= 1;
    vector<ll> a(A.begin(), A.end()), b(B.begin(), B.end());
    a.resize(n);
    b.resize(n);

    ntt(a, 1);
    ntt(b, 1);
    for (int i = 0; i < n; i++) a[i] = (i128) a[i] * b[i] % MOD;
    ntt(a, -1);

    a.resize(A.size() + B.size() - 1);
    return a;
}

int n, q, p[N], vis[N];

vll ans[N];
set<int> used;

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vll a, b, tmp;
        int st = i;
        while (!vis[st]) {
            tmp.emplace_back(st);
            vis[st] = 1;
            st = p[st];
        }
        int siz = tmp.size();
        a = b = tmp;
        reverse(a.begin(), a.end());
        vll res = multiply(a, b), h(siz);
        for (int j = 0; j <= siz * 2 - 2; j++) h[j % siz] += res[j];
        reverse(h.begin(), h.end());
        if (!used.contains(siz)) ans[siz].assign(siz, 0), used.insert(siz);
        for (int j = 0; j < siz; j++) ans[siz][j] += h[j];
    }
    while (q--) {
        int k;
        cin >> k;
        ll res = 0;
        for (const auto &it: used) res += ans[it][k % it];
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
