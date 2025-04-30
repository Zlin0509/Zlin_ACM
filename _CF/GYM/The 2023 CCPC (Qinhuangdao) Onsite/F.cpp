#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const int M = 2e7 + 5;
const ll inf = 1e18;
const ll mod = 998244353;
ll dp[N][4], a[N];
ll b[N], n, m;
ll cnt, isprime[N];
bool vis[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) isprime[++cnt] = i;
        for (int j = 1; j <= cnt && isprime[j] * i < N; j++) {
            vis[isprime[j] * i] = 1;
            if (i % isprime[j] == 0) break;
        }
    }
}

void solve() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = inf;
    }
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][2 - (a[i] & 1 ^ 1)];
        if (vis[a[i] + 1] == 0) dp[i][0] = min(dp[i][0], dp[i - 1][3]);
        if (vis[a[i] + a[i - 1]] == 0) dp[i][0] = min(dp[i][0], dp[i - 1][0]);

        dp[i][1] = dp[i - 1][2] + 1;
        if (!(a[i - 1] & 1)) dp[i][1] = min(dp[i][1], dp[i - 1][0]);

        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + 1;
        dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]) + (a[i] == 1 ? 0 : 1);

        if (vis[a[i - 1] + 1] == 0) {
            dp[i][3] = min(dp[i][3], dp[i - 1][0] + (a[i] == 1 ? 0 : 1));
        }
        if (a[i - 1] % 2) {
            dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        } else {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
