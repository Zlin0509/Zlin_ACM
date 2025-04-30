//
// Created by 27682 on 2025/3/7.
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
constexpr int N = 4e5 + 10;

ll fac[N], inv[N];

inline ll qpow(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mo;
        x = x * x % mo;
        y >>= 1;
    }
    return res;
}

inline void prework()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[N - 1] = qpow(fac[N - 1], mo - 2);
    for (int i = N - 2; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

inline ll co(ll n, ll k)
{
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin()
{
    prework();
    int n, k;
    cin >> n >> k;
    vll ans(n + 1);
    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n - i >= k)
        {
            ll res = co(n - i - 2, k - 2) * (n - (i + 2) + 1);
            res = (res + co(n - i - 1, k - 1) * 2 % mo) % mo;
            ans[i] = res;
        }
        else ans[i] = 0;
        tot = (tot + ans[i]) % mo;
    }
    ans[0] = (co(n * 2 - 2, k) - tot + mo) % mo;
    for (ll it : ans)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
