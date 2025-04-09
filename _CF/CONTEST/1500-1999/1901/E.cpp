//
// Created by Zlin on 2025/4/9.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 5e5 + 10;

int n;
vi e[N];
ll ans, dp[N], a[N];

inline void dfs(int u, int fa) {
    ans = max(ans, dp[u]);
    vll have;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        have.push_back(dp[v]);
    }
    sort(have.begin(), have.end(), greater<ll>());
    if (!have.empty())
        dp[u] = max(dp[u], have[0]);

    ll res = a[u];
    for (ll it: have) {
        if (it <= 0) break;
        res += it;
    }
    ans = max(ans, res);
    if (have.size() >= 2)
        ans = max(ans, have[0] + have[1]);
}

inline void Zlin() {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = a[i];
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
