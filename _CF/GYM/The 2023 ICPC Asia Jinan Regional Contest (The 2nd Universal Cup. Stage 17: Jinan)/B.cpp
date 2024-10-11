//
// Created by Zlin on 2024/10/11.
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

const int N = 1e5 + 10, NN = 1e3;
const ll mo = 998244353;

int n, k;
ll dp[N][NN];
vi e[N];

inline void dfs_1(int u, int fa) {
    for (auto v: e[u]) {
        if (v == fa) continue;
        dfs_1(v, u);
        for (int i = 1; i <= k + 1; i++)
            dp[u][i] = dp[v][i - 1];
        dp[u][0] = (dp[v][k] + dp[v][k + 1]) % mo;
    }
}

inline void dfs_2(int u, int fa) {

}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        for (int j = 1; j <= sqrt(n) + 1; j++)
            dp[i][j] = 0;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll ans;
    if (k <= sqrt(n)) {
        dfs_1(1, 0);
        ans = (dp[1][k] + dp[1][k + 1]) % mo;
    } else {
        dfs_2(1, 0);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}