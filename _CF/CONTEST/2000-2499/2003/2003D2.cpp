//
// Created by Zlin on 2024/9/10.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 2e5 + 15;
ll n = 0, m, mx, dp[N], used[N];
vi a, have, e[N];

inline void init() {
    mx = 0;
    if (have.size())
        for (int i = 0; i < have.back() + 10; i++) e[i].clear();
    have.clear();
    memset(dp, 0, sizeof dp);
    memset(used, 0, sizeof used);

}

inline void dfs(int u) {
    if (dp[u]) return;
    dp[u] = u;
    for (auto v: e[u]) {
        dfs(v);
        dp[u] = max(dp[u], dp[v]);
    }
}

inline void Zlin() {
    init();
    cin >> n >> m;
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        mx = max((int) mx, k);
        vi b(k);
        for (int j = 0; j < k; j++)
            cin >> b[j];
        sort(b.begin(), b.end());
        if (b[0])
            for (int j = 0; j < b[0] && a.size() < 2; j++)
                a.push_back(j);
        for (int j = 0; j < k - 1 && a.size() < 2; j++) {
            if (b[j] + 1 != b[j + 1])
                for (int q = b[j] + 1; q < b[j + 1] && a.size() < 2; q++)
                    a.push_back(q);
        }
        while (a.size() < 2)
            a.push_back(++b[k - 1]);
        e[a[0]].push_back(a[1]);
        if (!used[a[0]])
            have.push_back(a[0]);
        ++used[a[0]];
        a.clear();
    }
    sort(have.begin(), have.end());
    for (auto it: have) dfs(it);
    mx = have.back();
    for (auto it: have)
        if (used[it] >= 2)
            mx = max(mx, dp[it]);
    for (int i = 0; i <= mx; i++) {
        dp[i] = max(dp[i], (ll) i);
        dp[i] = max(dp[i], mx);
    }
    ll ans = 0;
    for (int i = 0; i <= mx && i <= m; i++) ans += dp[i];
    if (mx < m) ans += (m + mx + 1) * (m - mx) / 2ll;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}