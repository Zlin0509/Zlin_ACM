//
// Created by Zlin on 2025/2/6.
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

constexpr ll mo = 1E9 + 7;

ll inv(ll a)
{
    ll res = 1;
    ll b = mo - 2;
    while (b)
    {
        if (b & 1ll) res = res * a % mo;
        a = a * a % mo;
        b >>= 1ll;
    }
    return res;
}

// 计算不重合
inline ll cc(ll l1, ll r1, ll l2, ll r2)
{
    if (max(l1, l2) > max(r1, r2))
        return 0;
    ll res = (r1 - l1 + 1) * (l2 + r2) % mo * (r2 - l2 + 1) / 2;
    res -= (r2 - l2 + 1) * (l1 + r1) % mo * (r1 - l1 + 1) / 2;
    return res % mo;
}

// 计算重合
inline ll dd(ll len)
{
    --len;
    ll res = len * (len + 1) / 2 % mo + len * (len + 1) % mo * (2 * len + 1) / 6;
    return res % mo;
}

inline ll cal(ll l1, ll r1, ll l2, ll r2)
{
    ll res = 0;
    if (r1 > r2)
        swap(l1, l2), swap(r1, r2);
    if (l2 < r1)
    {
        if (l2 < l1)
        {
            res += dd(r1 - l1 + 1);
            res += cc(l2, l1 - 1, l1, r1);
        }
        else
            res += dd(r1 - l2 + 1);
        l2 = r1 + 1;
    }
    res += cc(l1, r1, l2, r2);
    return (res + mo) % mo;
}

inline void Zlin()
{
    ll n;
    cin >> n;
    pll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll l1, l2, r1, r2;
        l1 = a[i].first;
        r1 = a[i].second;
        l2 = a[i + 1].first;
        r2 = a[i + 1].second;
        ll sum = cal(l1, r1, l2, r2);
        sum = sum * inv(r2 - l2 + 1) * inv(r1 - l1 + 1) % mo;
        ans = (ans + sum) % mo;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
