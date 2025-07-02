//
// Created by 27682 on 2025/7/2.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 1010;

int n, k;
set<int> a;

int dp[N * 2], vis[N * 2];

inline void Zlin() {
    fill(dp, dp + N * 2, 1e9);
    cin >> n >> k;
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        a.insert(x - n);
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int it: a) {
        dp[it + N] = 1;
        pq.push({dp[it + N], it + N});
    }
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: a) {
            if (v + u > N * 2 || v + u < 0) continue;
            if (dp[v + u] > dp[v + N] + dp[u]) {
                a.insert(v + u - N);
                dp[v + u] = dp[v + N] + dp[u];
                pq.push({dp[v + u], v + u});
            }
        }
    }
    cout << (dp[N] == 1e9 ? -1 : dp[N]) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
