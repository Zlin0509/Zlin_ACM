//
// Created by Zlin on 2024/9/2.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

ll dp[55][100010]{}, a[55], b[55];

inline void Zlin() {
    int m, x;
    ll sum = 0;
    cin >> m >> x;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i], sum += b[i];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;
    dp[1][0] = x;
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int z = 1; z < i; z++) {
                if (dp[z][j] >= 0)dp[i][j] = max(dp[i][j], dp[z][j] + x);
                if (dp[z][j] >= a[i]) dp[i][j + b[i]] = max(dp[i][j + b[i]], dp[z][j] + x - a[i]);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= sum; i++)if (dp[m][i] >= 0) ans = max(ans, i);
    if (!a[1]) ans += b[1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}