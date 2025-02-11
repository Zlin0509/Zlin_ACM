//
// Created by Zlin on 2025/2/8.
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
    string s;
    cin >> n >> s;
    ll ans = 0, tag = 0;
    for (auto it : s)
    {
        int c = it - '0';
        ll now;
        if (c == 0)
        {
            now = tag + 10;
            ans += now;
            tag = now;
        }
        else if (c == 1)
        {
            now = max(tag - 5, 0ll);
            ans += now;
            tag = now;
        }
        else
        {
            now = max(tag - 10, 0ll);
            ans += now;
        }
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
