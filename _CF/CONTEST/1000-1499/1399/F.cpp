//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 3e3 + 10;

int n, m, f[N * 2], dp[N * 2][N * 2];
pii line[N];
vi bel[N * 2];

inline void Zlin() {
    cin >> n;
    vi idx;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].first >> line[i].second;
        idx.push_back(line[i].first);
        idx.push_back(line[i].second);
    }
    idx.push_back(0), idx.push_back(2e5 + 1);
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    m = idx.size();
    for (int i = 1; i <= m; i++) {
        bel[i].clear();
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        line[i].first = lower_bound(idx.begin(), idx.end(), line[i].first) - idx.begin();
        line[i].second = lower_bound(idx.begin(), idx.end(), line[i].second) - idx.begin();
        bel[line[i].second].push_back(line[i].first);
    }
    // i 右边界  j 左边界
    for (int i = 1; i < m; i++) {
        for (int k = 1; k < m; k++) dp[i][k] = max(dp[i][k], dp[i - 1][k]);
        sort(bel[i].begin(), bel[i].end(), greater<int>());
        for (int j: bel[i]) {
            for (int k = 1; k < m; k++) f[k] = dp[i][k];
            for (int k = 1; k <= j; k++) f[k] = max(f[k], 1 + dp[j - 1][k] + dp[i][j]);
            for (int k = 1; k < m; k++) dp[i][k] = max(f[k], dp[i][k + 1]);
        }
        for (int j = i; j; j--) dp[i][j] = max(dp[i][j], dp[i][j + 1]);
    }
    cout << dp[m - 1][1] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
