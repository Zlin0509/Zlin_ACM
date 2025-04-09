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
ll a[N], dp[N], ans;

vi e[N];

void dfs(int u, int fa) {
    ll x;
    vll d;
    ans = max(ans, dp[u]);
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u), d.push_back(dp[v]);
        ans = max(ans, a[u] + dp[v]), dp[u] = max(dp[u], dp[v]);
    }
    sort(d.begin(), d.end(), greater<ll>());
    if (d.size() >= 2) {
        x = d[0] + d[1], ans = max(ans, x);
        for (int i = 2; i < d.size() && d[i] > 0; i++) x += d[i];
        dp[u] = max(dp[u], a[u] + x);
    }
    if (d.size() >= 3) {
        x = d[0] + d[1] + d[2];
        for (int i = 3; i < d.size() && d[i] > 0; i++) x += d[i];
        ans = max(ans, a[u] + x);
    }
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
