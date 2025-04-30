//
// Created by Zlin on 2024/10/24.
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
ll dp[105][2605][2];
struct ffa {
    ll x;
    ll y;
} s[105];

bool cmp(ffa n1, ffa n2) {
    return n1.x > n2.x;
}

ll cnt[105], f[105];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 2600; j++) {
            dp[i][j][0] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i].x >> s[i].y;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + s[i].y;
        f[i] = f[i - 1] + s[i].x;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][s[i].y][0] = 0;
        if (dp[i][s[i].y * 2][0] > 1) {
            dp[i][s[i].y * 2][0] = 1;
            dp[i][s[i].y * 2][1] = s[i].y;
        }
        for (int j = 1; j <= 2600; j++) {
            if (j >= s[i].y && dp[i - 1][j - s[i].y][0] >= 0) {
                dp[i][j][0] = dp[i - 1][j - s[i].y][0];
                dp[i][j][1] = dp[i - 1][j - s[i].y][1];
            }
            if (j >= s[i].y * 2 && dp[i - 1][j - s[i].y * 2][0] >= 0) {
                dp[i][j][0] = dp[i - 1][j - s[i].y][0] + 1;
                dp[i][j][1] = dp[i - 1][j - s[i].y][1] + s[i].y;
            }
        }
    }
    ll ma = f[n];
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= 2600; j++) {
            if (cnt[i] + dp[i][j][1] == 2 * j && dp[i][j][0] >= 0 && dp[i][j][0] <= k) {
                ma = max(ma, f[i]);
            }
        }
    }
    if(ma<0) ma=0;
    cout << ma << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}