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

constexpr int N = 1e6 + 5;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n), cnt(n + 1);
    vector check(n + 1, false);
    for (int& it : a) cin >> it, cnt[it]++;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    ll ans = 1ll * n * (n - 1);
    for (int i : a)
    {
        if (check[i]) continue;
        ll val1 = 0, val2 = 0;
        for (int j = 1; i * j <= n; j++)
        {
            if (!cnt[i * j]) continue;
            check[i * j] ? val2 += cnt[i * j] : val1 += cnt[i * j];
            check[i * j] = true;
        }
        ans -= val1 * (val1 - 1) - val2 * (val2 - 1);
    }
    cout << ans / 2 << endl;
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
