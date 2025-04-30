//
// Created by Zlin on 2025/3/2.
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

constexpr ll mo = 998244353;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vll dp1(n + 1), dp2(n + 1), sum(n + 1);
    dp2[0] = sum[0] = 1;
    stack<pii> now;
    for (int i = 1; i <= n; i++)
    {
        while (!now.empty() && now.top().first > a[i])
            now.pop();
        int p = now.empty() ? 0 : now.top().second;
        dp1[i] = p ? (dp1[p] + dp2[p]) % mo : 0;
        dp2[i] = (dp1[p] + sum[i - 1] - (p ? sum[p - 1] : 0) + mo) % mo;
        sum[i] = (sum[i - 1] + dp2[i]) % mo;
        now.push({a[i], i});
    }
    cout << (dp1[n] + dp2[n]) % mo << endl;
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
