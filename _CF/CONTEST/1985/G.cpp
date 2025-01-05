#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
ll l, r, k;

ll quick_pow(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y % 2 == 0)
        return quick_pow(x * x % MOD, y / 2);
    return quick_pow(x * x % MOD, y / 2) * x % MOD;
}

void solve()
{
    cin >> l >> r >> k;
    // cout << 9 / k + 1 << '\n';
    // cout << quick_pow(9 / k + 1, r) << '\n';
    cout << (quick_pow(9 / k + 1, r) - quick_pow(9 / k + 1, l) + MOD) % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // cout << quick_pow(2, 5);

    int T;
    cin >> T;
    while (T--)
        solve();
}