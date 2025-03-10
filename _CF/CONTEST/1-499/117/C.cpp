//
// Created by Zlin on 2025/1/19.
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
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    vi to(n + 1, 0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == '1' && (!to[i] || a[j][to[i]] == '1'))
                to[i] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[to[i]][j] == '1' && a[j][i] == '1')
            {
                cout << i << " " << to[i] << " " << j << '\n';
                return;
            }
    cout << "-1" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
