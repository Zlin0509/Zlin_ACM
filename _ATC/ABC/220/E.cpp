//
// Created by 27682 on 2025/3/16.
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

inline void Zlin()
{
    ll n, d;
    cin >> n >> d;
    ll tag = 1;
    ll ans = 0;
    vll fac(n + 1);
    vll inv(n + 1);
    fac[1] = 1;
    for (int i = 2; i < n; i++)
        fac[i] = fac[i - 1] * 2 % mo;
    for (int i = 1; i < n - 1; i++)
    {
        if ((i - 1) * 2 < d)
            continue;
        inv[i] =
    }
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
