//
// Created by 27682 on 2025/7/15.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

constexpr int N = 422;
constexpr ll inf = 1e18;

int n;
ll a[N];
vector<pair<ll, ll> > dp[N][N];

ll cal(ll x, ll y) {
    return min(x, y) * (ll) ceil(log2(x + y));
}

ll find(ll tag, int i, int j) {
    if (dp[i][j].empty()) return inf;
    int l = 0, r = (int) dp[i][j].size() - 1, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (dp[i][j][mid].first <= tag) l = mid;
        else r = mid - 1;
    }
    if (dp[i][j][l].first <= tag) return dp[i][j][l].second;
    return inf;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j].clear();
        }
    }
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    for (int len = 1; len < n; len++) {
        for (int l = 1, r; l + len - 1 <= n; l++) {
            r = l + len - 1;
            if (l == r) dp[l][r].emplace_back(0, 0);
            else {
                for (int k = l; k < r; k++) {
                    ll len1 = a[k] - a[l - 1], len2 = a[r] - a[k], dif = abs(len1 - len2);
                    ll res1 = find(dif, l, k), res2 = find(dif, k + 1, r);
                    if (res1 == inf || res2 == inf) continue;
                    dp[l][r].emplace_back(dif, cal(len1, len2) + res1 + res2);
                }
                sort(dp[l][r].begin(), dp[l][r].end());
                for (int i = 1; i < dp[l][r].size(); i++)
                    dp[l][r][i].second = min(dp[l][r][i].second, dp[l][r][i - 1].second);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        ll len1 = a[i], len2 = a[n] - a[i], dif = abs(len1 - len2);
        ll res1 = find(dif, 1, i), res2 = find(dif, i + 1, n);
        if (res1 == inf || res2 == inf) cout << -1 << ' ';
        else cout << res1 + res2 + cal(len1, len2) << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
