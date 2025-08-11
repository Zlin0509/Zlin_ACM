//
// Created by Zlin on 2025/8/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int mo = 998244353;

int n, a[3005];
ll dp[3005][3005], ans[3005], sum;

/*

6
4 5 1 6 2 3
36

6
5 4 1 6 2 3
45

7
1 2 3 4 5 6 7
429

7
7 6 5 4 3 2 1
429

5
5 2 4 3 1
19

 */

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], ans[i] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = 0;
    ans[0] = ans[1] = 1, dp[1][a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        sum = 0;
        for (int j = 1; j < a[i]; j++) {
            sum = (sum + dp[i - 1][j]) % mo;
            if (dp[i - 1][j]) dp[i][j] = sum;
        }
        int lx = i;
        while (lx && a[lx] >= a[i]) --lx;
        for (int j = lx; j <= i - 2; j++) {
            dp[j + 1][a[i]] = ans[j];
            ans[j + 1] = (ans[j + 1] + dp[j + 1][a[i]]) % mo;
        }
        dp[i][a[i]] = ans[i - 1];
        for (int j = 1; j <= n; j++) ans[i] = (ans[i] + dp[i][j]) % mo;
    }
    cout << ans[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
