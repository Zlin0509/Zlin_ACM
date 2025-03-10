//
// Created by 27682 on 2025/3/3.
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

constexpr int inf = 1e8;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vector dp(1 << n, vi(n, inf));
    vector dis(n, vi(n, 0));
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = 1;
    for (int i = 1; i <= q; i++) {
        int x;
        char c;
        cin >> x >> c;
        --x;
        if (c == '+') {
            a[x]++;
            for (int j = 0; j < n; j++)
                dis[x][j] = max(dis[x][j], a[x] - b[j] + 1);
        } else b[x]++;
    }
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    for (int i = 0; i < 1 << n; i++)
        for (int r = 0; r < n; r++)
            if (i >> r & 1)
                for (int l = 0; l < n; l++)
                    if (i >> l & 1)
                        dp[i][r] = min(dp[i][r], dp[i - (1 << r)][l] + dis[l][r]);
    int ans = inf;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i] + a[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}