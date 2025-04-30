//
// Created by 27682 on 2025/3/14.
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

inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    if (k & 1)
    {
        cout << 0 << endl;
        return;
    }
    int z = n / k;
    n %= k;
    ll ans = 0;
    // to me
    ans += 1ll * z * k / 2;
    // to other
    ans += 1ll * z * (z - 1) * k / 2;
    // the last
    ans += 1ll * n * z;
    ans += max(0, n - k / 2);
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
