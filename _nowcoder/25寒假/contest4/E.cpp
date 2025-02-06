//
// Created by Zlin on 2025/2/6.
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

int n, m;
vector<vll> a;
vll suml, sumr;

inline void Zlin()
{
    cin >> n >> m;
    a.assign(n + 1, vll(m + 1, 0));
    suml.assign(m + n + 1, 0);
    sumr.assign(m + n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sumr[n + j - i + 1] += a[i][j];
            suml[j + i - 1] += a[i][j];
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int l, r;
            r = n + j - i + 1;
            l = j + i - 1;
            ans = max(ans, suml[l] + sumr[r] - a[i][j]);
        }
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
