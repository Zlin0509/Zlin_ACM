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

int n, h;
ll f[40][40];

inline void Zlin()
{
    cin >> n >> h;
    for (int i = 0; i <= n; ++i)
        f[0][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 0; k < j; ++k)
                f[j][i] += f[k][i - 1] * f[j - k - 1][i - 1];
    cout << f[n][n] - f[n][h - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
