//
// Created by Zlin on 2025/1/10.
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
    string s;
    cin >> s;
    int n = s.length();
    vi dp(n, 0);
    int ans1 = 0, ans2 = 0;
    for (int i = 1, tag; i < n; i++)
    {
        if (s[i] == '(') continue;
        tag = i - 1;
        while (tag > 0 && dp[tag])
            tag = tag - dp[tag];
        if (tag == -1 || s[tag] != '(') continue;
        dp[i] = i - tag + 1;
        while (tag > 0 && dp[tag - 1])
            tag = tag - dp[tag - 1];
        dp[i] = i - tag + 1;
    }
    for (int i = 0; i < n; i++)
        ans1 = max(ans1, dp[i]);
    // for (int i = 0; i < n; i++)
    //     cout << dp[i] << ' ';
    // cout << '\n';
    if (ans1)
    {
        for (int i = 0; i < n; i++)
            if (dp[i] == ans1)
                ++ans2;
    }
    else ans2 = 1;
    cout << ans1 << ' ' << ans2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
