//
// Created by Zlin on 2025/3/3.
//

#include "bits/stdc++.h"

#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector a(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> a[i][j];
    vector dp(n + 1, vi());
    dp[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        priority_queue<tuple<int, int, int>> now;
        now.push({dp[i - 1][0], i - 1, 0});
        for (int j = i - 2; j >= 0; j--)
            now.push({dp[j][0] + a[j + 2][i], j, 0});
        now.push({a[1][i], -1, 0});
        while (!now.empty() && dp[i].size() < k) {
            auto [val, j, num] = now.top();
            now.pop();
            dp[i].push_back(val);
            if (j < 0 || ++num >= dp[j].size())
                continue;
            if (j == i - 1)
                now.push({dp[j][num], j, num});
            else
                now.push({dp[j][num] + a[j + 2][i], j, num});
        }
    }
    for (int i: dp[n])
        cout << i << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
