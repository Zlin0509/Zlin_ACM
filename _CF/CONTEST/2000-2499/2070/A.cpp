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

inline void Zlin()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= min(2, n); i++)
        ++ans;
    if (n >= 15)
    {
        int cnt = n / 15;
        n -= cnt * 15;
        ans += min(n + 1, 3);
        ans += (cnt - 1) * 3;
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
