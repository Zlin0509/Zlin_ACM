//
// Created by Zlin on 2024/10/29.
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

const int N = 20;
const int inf = 1e9;

int n, dp[1 << N][N];
vi e[N];
string a[N][2];

// 初始化
void init() {
    for (int i = 0; i < (1 << n); i++)
        memset(dp[i], -inf, sizeof(dp[i]));
    for (int i = 0; i < n; i++)
        e[i].clear();
}

int hmd() {
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == -inf) continue;
            for (int v: e[u]) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = max(dp[newMask][v], dp[mask][u] + 1);
            }
        }
    }
    int res = 1;
    for (int i = 0; i < n; i++)
        res = max(res, dp[(1 << n) - 1][i]);
    return res;
}

inline void Zlin() {
    cin >> n;
    init();
    for (int i = 0; i < n; i++)cin >> a[i][0] >> a[i][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((a[i][0] == a[j][0] || a[i][1] == a[j][1])) {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    cout << n - hmd() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin(); // 多组测试
    return 0;
}