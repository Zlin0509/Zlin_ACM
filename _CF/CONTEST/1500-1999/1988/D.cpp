//
// Created by Zlin on 2024/9/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 3e5 + 5;
int n;
ll dp[N][24], mn[30], a[N];
vi e[N];

inline void dfs(int u, int fa) {
    for (int i = 1; i <= 22; i++) dp[u][i] = a[u] * i;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ll t = 1e18;
        mn[23] = 1e18;
        for (int i = 22; i >= 1; i--) mn[i] = min(mn[i + 1], dp[v][i]);
        for (int i = 1; i <= 22; i++) {
            dp[u][i] += min(t, mn[i + 1]);
            t = min(t, dp[v][i]);
        }
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << *min_element(dp[1] + 1, dp[1] + 23) << '\n';
    for (int i = 1; i <= n; i++)
        e[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}