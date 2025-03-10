//
// Created by Zlin on 2025/1/18.
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
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << n / 2 * (n / 2 + 1) << '\n';
        for (int i = 1; i <= n / 2; i++)
            for (int j = n / 2 + 1; j <= n; j++)
                cout << i << ' ' << j << '\n';
    }
    else
    {
        cout << n / 2 * n / 2 << '\n';
        for (int i = 1; i <= n / 2; i++)
            for (int j = n / 2 + 1; j <= n; j++)
                cout << i << ' ' << j << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
