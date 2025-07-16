//
// Created by Zlin on 2025/1/21.
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
    vi a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum != 1ll * n * (n + 1) / 2)
    {
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    ll tag = 0;
    sum = 0;
    ll ans = 0;
    for (auto it : a)
    {
        ++tag;
        if (tag >= it)
            continue;
        ans += it - tag;
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
