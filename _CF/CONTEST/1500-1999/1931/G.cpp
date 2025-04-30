//
// Created by 27682 on 2025/3/10.
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

constexpr ll mo = 998244353;
constexpr int N = 4e6;

ll inv[N + 10], fac[N + 10];

inline ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void dd()
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[N] = qpow(fac[N], mo - 2);
    for (int i = N - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

inline ll co(int n, int k)
{
    if (k == 0) return 1;
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin()
{
    int a, b, c, d;
    ll ans = 0, k;
    cin >> a >> b >> c >> d;
    if (abs(a - b) >= 2)
    {
        cout << 0 << endl;
        return;
    }
    if (!a && !b)
    {
        cout << (c && d ? 0 : 1) << endl;
        return;
    }
    if (!a || !b)
    {
        cout << 1 << endl;
        return;
    }
    if (!c && !d)
    {
        if (a == b)
            cout << 2 << endl;
        else
            cout << 1 << endl;
        return;
    }
    if (!c || !d)
    {
        k = min(a, b);
        ans = co(max(c, d) + k, k);
        if (a == b)
            ans = (ans + co(max(c, d) + k - 1, k - 1)) % mo;
        cout << ans << endl;
        return;
    }
    if (a == b)
    {
        k = a;
        ans = (ans + co(c + k, k) * co(d + k - 1, k - 1) % mo) % mo;
        ans = (ans + co(d + k, k) * co(c + k - 1, k - 1) % mo) % mo;
    }
    else
    {
        k = min(a, b);
        ans = (ans + co(c + k, k) * co(d + k, k) % mo) % mo;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    dd();
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
