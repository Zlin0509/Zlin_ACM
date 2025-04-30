//
// Created by Zlin on 2024/9/20.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> dp(n + 2, -1);
    dp[0] = k;
    for (int i = 1; i <= n + 1; i++) {
        if (i != n + 1 && s[i - 1] == 'C')
            continue;
        for (int t = 1; t <= m; t++)
            if (i - t >= 0 && (i - t == 0 || s[i - t - 1] == 'L'))
                dp[i] = max(dp[i], dp[i - t]);
        if (i > 1 && s[i - 2] == 'W')
            dp[i] = max(dp[i], dp[i - 1] - 1);
    }
    if (dp[n + 1] >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}