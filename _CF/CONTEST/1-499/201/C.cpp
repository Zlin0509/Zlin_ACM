//
// Created by Zlin on 2025/1/16.
//

#include "bits/stdc++.h"

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
    int n;
    cin >> n;
    vll a(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    vector<vll> f(n + 1, vll(2, 0)), g(n + 1, vll(2, 0));
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > 1) f[i][1] = f[i - 1][1] + a[i - 1] / 2 * 2;
        f[i][0] = max(f[i][1], f[i - 1][0] + a[i - 1] - !(a[i - 1] & 1));
        f[i][0] = max(f[i][0], f[i - 1][1] + a[i - 1]);
    }
    for (int i = n - 1; i; i--)
    {
        if (a[i] > 1) g[i][1] = g[i + 1][1] + a[i] / 2 * 2;
        g[i][0] = max(g[i][1], g[i + 1][0] + a[i] - !(a[i] & 1));
        g[i][0] = max(g[i][0], g[i + 1][1] + a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, max(f[i][0] + g[i][1], f[i][1] + g[i][0]));
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
