//
// Created by Zlin on 2024/12/20.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

inline void Zlin()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vll> a(n, vll(m, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];

    vll f1(m, LLONG_MAX), f2(m, LLONG_MAX), f(m, LLONG_MAX);

    for (ll dif = 0; dif < m; dif++)
    {
        f1[0] = a[0][dif] + dif * k;
        for (ll j = 1, now; j < m; j++)
        {
            now = (j + dif) % m;
            f1[j] = min(f1[j], f1[j - 1] + a[0][now]);
        }
        for (ll j = 0; j < m; j++)
            f[j] = min(f[j], f1[j]);

        fill(f1.begin(), f1.end(), LLONG_MAX);
    }

    f2 = f;
    fill(f.begin(), f.end(), LLONG_MAX);

    for (ll i = 1; i < n; i++)
    {
        for (ll dif = 0; dif < m; dif++)
        {
            f1[0] = min(f1[0], f2[0] + a[i][dif] + dif * k);
            for (ll j = 1, now; j < m; j++)
            {
                now = (j + dif) % m;
                f1[j] = min(f1[j], f2[j] + a[i][now] + dif * k);
                f1[j] = min(f1[j], f1[j - 1] + a[i][now]);
            }
            for (ll j = 0; j < m; j++)
                f[j] = min(f[j], f1[j]);

            fill(f1.begin(), f1.end(), LLONG_MAX);
        }
        f2 = f;
        fill(f.begin(), f.end(), LLONG_MAX);
    }

    cout << f2[m - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll ttt = 1; // 9️⃣ 替换 int 为 long long
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}
