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

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int& it : a) cin >> it;
    string s;
    cin >> s;
    ll cnt = 0;
    for (char it : s)
        if (it == '?')
            ++cnt;
    cnt -= s[0] == '?';
    ll ans = 0;
    if (s[0] == '?' || s[0] == 'L')
    {
        bool check = true;
        for (int i = 1; i < n - 1; i++)
            if (s[i] == 'R')
                check = false;
        if (check && s[n - 1] == '?')
            ans = 2;
    }
    if (s[0] == '?' || s[0] == 'R')
        ans = (ans + qpow(2, cnt)) % mo;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
