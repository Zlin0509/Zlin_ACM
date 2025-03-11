//
// Created by Zlin on 2025/2/7.
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
    string s;
    cin >> s;
    s = ' ' + s;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            int cnt = 0;
            for (int k = i; k <= j; k++)
                cnt += s[k] == '1';
            if (cnt >= (i + 1) / 2)
                ans += (i + 1) / 2;
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
