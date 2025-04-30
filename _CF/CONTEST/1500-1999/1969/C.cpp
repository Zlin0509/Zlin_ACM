//
// Created by Zlin on 2024/9/2.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
const ll INF = 1e17;
ll dp[300010][11];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<ll> sum(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            ll mm = INF;
            for (int q = 0; q + j <= k && i + q <= n; q++) {
                mm = min(mm, a[i + q]);
                dp[i + q][q + j] = min(dp[i + q][q + j], dp[i - 1][j] + mm * (q + 1));
            }
        }
    }
    ll ans = sum[n];
    for (int i = 1; i <= k; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}