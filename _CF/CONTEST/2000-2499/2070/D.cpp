//
// Created by Zlin on 2025/2/27.
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
    vi f(n + 1), dep(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> f[i], dep[i] = dep[f[i]] + 1;
    vector indep(n + 1, vi());
    for (int i = 1; i <= n; i++)
        indep[dep[i]].push_back(i);
    vll sum(n + 1, 0), sum1(n + 1, 0);
    sum[0] = sum1[1] = 1;
    for (int id : indep[1])
    {
        sum1[id] = 1;
        sum[1] = (sum[1] + sum1[id]) % mo;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int id : indep[i])
        {
            sum1[id] = (sum[i - 1] - sum1[f[id]] + mo) % mo;
            sum[i] = (sum[i] + sum1[id]) % mo;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + sum1[i]) % mo;
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
