//
// Created by Zlin on 2025/4/30.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 1e9 + 7;

int n, I, J, X, Y, ans;

inline void Zlin() {
    cin >> n >> I >> J >> X >> Y;
    if (X > Y) {
        X ^= Y ^= X ^= Y;
        I ^= J ^= I ^= J;
    }
    vector dp(n + 1, vi(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (i == X) {
            if (X >= I)
                dp[i][I] += dp[i - 1][I - 1];
            if (X - (n - I + 1) >= 0)
                dp[i][X - (n - I + 1)] += dp[i - 1][X - (n - I + 1)];
        } else if (i == Y) {
            if (Y >= J)
                dp[i][J] += dp[i - 1][J - 1];
            if (Y - (n - J + 1) >= 0)
                dp[i][Y - (n - J + 1)] += dp[i - 1][Y - (n - J + 1)];
        } else {
            for (int j = 0; j < i; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mo;
                dp[i][j + 1] += dp[i - 1][j];
                dp[i][j + 1] %= mo;
            }
        }
    }
    if (Y != n) {
        for (int i = 1; i <= n - 2; i++) {
            ans += dp[n - 1][i];
            ans %= mo;
        }
    } else if (J != n && J != 1) ans = dp[n - 1][J - 1];
    else ans = 0;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
