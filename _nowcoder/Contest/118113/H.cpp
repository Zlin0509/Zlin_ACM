//
// Created by 27682 on 2025/9/27.
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

constexpr int N = 1e5 + 5;

int n, dp[N][4];
string a[3];

inline void Zlin() {
    cin >> n >> a[0] >> a[1] >> a[2];
    memset(dp[0], 0, sizeof(dp[0]));
    if (a[0][0] == '1' && a[1][0] == '1') dp[0][1] = 1;
    if (a[0][0] == '1' && a[2][0] == '1') dp[0][2] = 1;
    if (a[1][0] == '1' && a[2][0] == '1') dp[0][3] = 1;
    for (int i = 1; i < n; i++) {
        memset(dp[i], 0, sizeof(dp[i]));
        if (a[0][i] == '1' && a[1][i] == '1') dp[i][1] = max({1, dp[i - 1][0] + 1, dp[i - 1][2] + 1, dp[i - 1][3] + 1});
        if (a[0][i] == '1' && a[2][i] == '1') dp[i][2] = max({1, dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][3] + 1});
        if (a[1][i] == '1' && a[2][i] == '1') dp[i][3] = max({1, dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2] + 1});
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
    }
    int ans = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
