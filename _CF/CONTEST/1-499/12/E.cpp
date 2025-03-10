//
// Created by Zlin on 2025/1/14.
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
    vector<vi> ans(n, vi(n, 0));
    for (int i = 0, tag; i < n - 1; i++)
    {
        tag = i;
        for (int j = 0; j < n - 1; j++)
        {
            ++tag;
            if (tag == n) tag = 1;
            ans[i][j] = tag;
        }
    }
    for (int i = 0; i < n; i++)
        ans[n - 1][i] = ans[i][n - 1] = ans[i][i], ans[i][i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
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
