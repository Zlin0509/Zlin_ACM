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
constexpr int N = 1e5 + 20;
constexpr ll mo = 998244353;
// 快速幂函数：计算 a^b % mo
ll qpow(ll a, ll b)
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

inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    int x;
    cin >> x;
    vi a(k);
    for (int& it : a)
        cin >> it;
    deque<pll> f, g;
    sort(a.begin(), a.end());
    for (auto it : a)
        f.push_back({it, 1});
    ll r;
    ll len = 1;
    ll ans = 1;
    auto check = [&](int id)
    {
        int lx = (x - 1) / len * len + 1;
        int rx = (x - 1) / len * len + len;
        return lx <= id && id <= rx;
    };
    ll fac = qpow(2, mo - 2) % mo;
    while (!f.empty())
    {
        len *= 2;
        while (!f.empty())
        {
            pll u = *f.begin();
            f.pop_front();
            if (check(u.first))
                ans = ans * (1 - u.second + mo) % mo;
            else
            {
                u.second = u.second * fac % mo;
                int id = u.first;
                r = (id - 1) / len * len + len;
                while (!f.empty() && f.begin()->first <= r)
                {
                    ll v = f.begin()->second * fac % mo;
                    u.second = (u.second + v) % mo;
                    f.pop_front();
                }
                g.push_back(u);
            }
        }
        while (!g.empty())
        {
            f.push_back(*g.begin());
            g.pop_front();
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
