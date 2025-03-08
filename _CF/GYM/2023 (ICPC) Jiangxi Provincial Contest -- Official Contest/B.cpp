//
// Created by Zlin on 2025/3/8.
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

inline void Zlin()
{
    int k;
    cin >> k;
    vll a(k);
    for (ll& it : a)
        cin >> it;
    ll n, m, x;
    vll sum(k + 1);
    for (int i = 0; i < k; i++)
        sum[i + 1] = sum[i] + a[i];
    cin >> n >> m >> x;
    ll ans = n;
    for (int i = 1; i <= k; i++)
    {
        ll a, b, c;
        c = sum[k] % m;
        a = (x + sum[i - 1]) % m;
        b = (x + sum[i]) % m;
        if (a > b)
            ans -= count_valid_k(0, m - a, c, m, 0, (n - i) / k);
        else
            ans -= count_valid_k(m - b, m - a, c, m, 0, (n - i) / k);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
