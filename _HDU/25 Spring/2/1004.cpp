//
// Created by 27682 on 2025/3/14.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[26][26];

inline void Zlin()
{
    string s;
    string z;
    cin >> s >> z;
    int k = 0;
    for (auto it : z)
        k = (k * 10 + (it - '0')) % 100;
    if (z.size() > 2)
        k = 100;
    k = min(k, 40);
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            dp[i][j] = 0;
    while (k--)
    {
        for (char it : s)
        {
            int k = it - 'a';
            for (int j = 0; j < k; j++)
                for (int i = 0; i <= j; i++)
                    if (dp[i][j])
                        dp[i][k] = max(dp[i][k], dp[i][j] + 1);
            dp[k][k] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
