//
// Created by Zlin on 2025/7/29.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int m, s, t;
int n;
int a[N], k[N], b[N], c[N], sum[N];

int dp[N][N][N];

inline bool work(int p) {
    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= t; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int j = 0; j <= n; j++) {
        for (int i = 0, tk, rk; i <= t; i++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j][k] >= s) return true;
                if (i + 1 <= t) dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + sum[j]);
                if (j + 1 <= n) {
                    // 不触发
                    tk = (a[j + 1] + sum[j] - 1) / sum[j];
                    if (i + tk <= t) dp[i + tk][j + 1][k + tk] = max(dp[i + tk][j + 1][k + tk], dp[i][j][k]);
                    // 触发
                    if (!p) continue;
                    tk = (a[j + 1] - c[j + 1] + sum[j] - 1) / sum[j];
                    rk = (b[j + 1] + p - 1) / p;
                    if (i + tk <= t && k + tk - rk >= 0) {
                        dp[i + tk][j + 1][k + tk - rk] = max(dp[i + tk][j + 1][k + tk - rk], dp[i][j][k]);
                    }
                }
            }
        }
    }
    return false;
}

inline void Zlin() {
    cin >> m >> s >> t >> n;
    sum[0] = m;
    for (int i = 1; i <= n; i++) cin >> a[i] >> k[i] >> b[i] >> c[i], sum[i] = sum[i - 1] + k[i];
    int l = 0, r = 1e6, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (work(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (l == 1e6 ? -1 : l) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
