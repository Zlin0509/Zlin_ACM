//
// Created by 27682 on 2025/3/17.
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

ll fac[200010], inv[200010];

ll q_pow(ll a, ll b)
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

void dd()
{
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[200000] = q_pow(fac[200000], mo - 2);
    for (int i = 199999; i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

ll comp(int n, int k)
{
    if (!k || n == k)
        return 1;
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    ll ans = 0, cnt = 0;
    if (k == 1)
    {
        cnt = n & 1 ? 2 : 1;
        if (n & 1)
            ans = n / 2;
        n >>= 1;
        ans += 1ll * (n - 1) * n;
        cout << ans << ' ' << cnt << endl;
        return;
    }
    ll tag = 2 * k, dep = 1;
    if (n <= tag)
    {
        ans = 0, cnt = comp(k - 1, n - k - 1);
        cout << ans << ' ' << cnt << endl;
        return;
    }
    n -= tag;
    dep = n / tag;
    ans = dep * (dep + 1) / 2 * tag;
    n %= tag;
    ans += n * (dep + 1);
    for (int i = max(0, n - k - 1), val; i <= min(k - 1, n / 2); i++)
    {
        val = n - i * 2;
        cnt = (cnt + comp(k - 1, i) * comp(k + 1 - i, val) % mo) % mo;
    }
    cout << ans << ' ' << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
