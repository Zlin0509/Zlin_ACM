//
// Created by Zlin on 2025/3/15.
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

int x, k;

int f[110][110];

void dfs(int u, int len, ll mul, ll gg)
{
    for (int i = u + 1; i <= x; i++)
        dfs(i, len + 1, mul * i, gcd(gg, i));
}

inline void Zlin()
{
    cin >> x >> k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
