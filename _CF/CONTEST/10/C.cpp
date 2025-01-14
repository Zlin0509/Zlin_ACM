//
// Created by Zlin on 2025/1/13.
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
    ll n, ans = 0;
    cin >> n;
    vll d(10);
    for (int i = 1; i <= n; i++) d[i % 9]++;
    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) ans += d[i] * d[j] * d[i * j % 9];
    for (int i = 1; i <= n; i++) ans -= n / i;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
