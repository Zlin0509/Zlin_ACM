//
// Created by Zlin on 2025/3/20.
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
    int n;
    cin >> n;
    vll a(n), cnt(n + 1), cnt1(n + 1), val(n + 1);
    for (ll& it : a) cin >> it, cnt[it]++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; i * j <= n; j++)
            cnt1[i * j] += cnt[i];
    for (int i = n; i; i--)
    {
        for (int j = 1; i * j <= n; j++)
            val[i] += cnt[i * j];
        val[i] = (val[i] - 1) * val[i] / 2;
        for (int j = 2; i * j <= n; j++)
            val[i] -= val[i * j];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (!cnt1[i])
            ans += val[i];
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
