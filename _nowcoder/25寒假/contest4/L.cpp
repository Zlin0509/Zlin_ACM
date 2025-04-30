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

constexpr ll mo = 1e9 + 7;
constexpr int N = 3e5 + 10;

ll suma[33][N], sumb[33][N], sum1[33][N], sum0[33][N];
int n, q;
int a[N], b[N];

inline void Zlin()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = n; i >= 1; i--)
    {
        for (int k = 0; k < 30; k++)
        {
            suma[k][i] = suma[k][i + 1] + (a[i] >> k & 1);
            sumb[k][i] = sumb[k][i + 1] + (b[i] >> k & 1);
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int k = 0; k < 30; k++)
        {
            sum1[k][i] = sum1[k][i + 1];
            sum0[k][i] = sum0[k][i + 1];
            if (a[i] >> k & 1)
                sum1[k][i] += n - i + 1 - sumb[k][i];
            else
                sum0[k][i] += sumb[k][i];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ll ans = 0;

        for (int k = 0; k < 30; k++)
        {
            ll cnt1a = suma[k][l] - suma[k][r + 1];
            ll cnt0a = r - l + 1 - cnt1a;
            ll cnt1b = sumb[k][r + 1];
            ll cnt0b = n - r - cnt1b;

            ll all = sum1[k][l] - sum1[k][r + 1] + sum0[k][l] - sum0[k][r + 1] - cnt1a * cnt0b
                - cnt0a * cnt1b;
            all %= mo;
            ans = (ans + all * (1ll << k)) % mo;
        }

        cout << ans << endl;
    }
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
