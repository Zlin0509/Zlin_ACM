//
// Created by Zlin on 2024/9/6.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 5;
int n, m, cnt;
int used[N], lx[N];
vi rx[N];
int l[N], r[N], b[N];
int dp[N][2];

void init() {
    for (int i = 1; i <= n; i++) rx[i].clear(), b[i] = used[i] = dp[i][0] = dp[i][1] = 0;
}

inline void Zlin() {
    cin >> n >> m;

    init();

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        ++b[l[i]], --b[r[i] + 1];
        rx[r[i]].push_back(i);
        ++used[l[i]];
    }
    int ll = 1;
    for (int i = 1; i <= n; i++) {
        while (!used[ll] && ll < i) ++ll;
        lx[i] = ll;
        for (auto it: rx[i])
            --used[l[it]];
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += b[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[lx[i] - 1][0], dp[lx[i] - 1][1]) + cnt;
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}