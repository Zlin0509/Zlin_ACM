//
// Created by Zlin on 2025/8/14.
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

int n, m;
int a[410], dp[410][2];

inline int cal(int t1, int t2) {
    if (t1 >= a[1]) dp[1][0] = t1 - a[1];
    else dp[1][0] = 1e9;
    if (t2 >= a[1]) dp[1][1] = t2 - a[1];
    else dp[1][1] = 1e9;
    for (int i = 2, tmp, tmp1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1e9;
        tmp = t1 - a[i];
        if (tmp >= 0) {
            tmp1 = t1 - a[i - 1];
            if (tmp1 >= 0) dp[i][0] = min(dp[i - 1][0] + max(0, tmp - tmp1), dp[i][0]);
            tmp1 = t2 - a[i - 1];
            if (tmp1 >= 0) dp[i][0] = min(dp[i - 1][1] + max(0, tmp - tmp1), dp[i][0]);
        }
        tmp = t2 - a[i];
        if (tmp >= 0) {
            tmp1 = t1 - a[i - 1];
            if (tmp1 >= 0) dp[i][1] = min(dp[i - 1][0] + max(0, tmp - tmp1), dp[i][1]);
            tmp1 = t2 - a[i - 1];
            if (tmp1 >= 0) dp[i][1] = min(dp[i - 1][1] + max(0, tmp - tmp1), dp[i][1]);
        }
    }
    return min(dp[n][0], dp[n][1]);
}

/*

1
6 2
1 2 1 4 5 6

3 (3, 6)

 */

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1e9;
    if (m == 2) for (int i = 1; i <= 200; i++) for (int j = i; j <= 200; j++) ans = min(ans, cal(i, j));
    else for (int i = 1; i <= 200; i++) ans = min(ans, cal(i, i));
    // for (int i = 1; i <= 100; i++) {
    //     for (int j = i; j <= 100; j++) {
    //         if (ans == cal(i, j)) {
    //             cout << i << ' ' << j << endl;
    //             break;
    //         }
    //     }
    // }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
