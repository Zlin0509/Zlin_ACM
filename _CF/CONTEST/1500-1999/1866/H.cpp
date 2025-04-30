//
// Created by Zlin on 2025/3/24.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 998244353;
constexpr int N = 2e5;

inline ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll fac[N + 5], inv[N + 5];

inline void dd()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mo;
    inv[N] = qpow(fac[N], mo - 2);
    for (int i = N - 1; i; i--) inv[i] = inv[i + 1] * (i + 1) % mo;
}

ll cal(int n, int k)
{
    return fac[n] * inv[n - k] % mo;
}

inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    vi val(n + 1);
    for (int i = n; i; i--)
        val[i] = k - n + i;
    ll ans = 1, pre = 1, now;
    for (int i = n, z; i; i--)
    {
        if (!val[i]) break;
        z = n - i + 1;
        now = pre * qpow(z + 1, val[i]) % mo * qpow(qpow(z, val[i]), mo - 2) % mo;
        ans = (ans + cal(n, z) * (now - pre + mo) % mo) % mo;
        pre = now;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    dd();
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
