#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1005;
const int M = 10010;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
ll n, m, k;
ll mx[20], a[N][20], dp[20][1 << 13];
ll b[N];
ll c[1001][1 << 13];
vector<int> g[1 << 13];

void dfs(int x, int fa, int res) {
    if (x == 13) {
        g[res].push_back(fa);
        return;
    }
    dfs(x + 1, fa, res | (1 << x));
    if (!(fa >> x & 1)) {
        dfs(x + 1, fa, res);
    }
}

inline ll lowbit(ll x) {
    return x & -x;
}

void solve() {
    cin >> n >> m >> k;
    memset(mx, 0, sizeof(mx));
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx[j] = max(mx[j], a[i][j]);
        }
        for (int j = 0; j < (1 << m); j++) c[i][j] = 0;
        for (int j = 1; j < (1 << m); j++) {
            ll x = lowbit(j);
            ll y = log(x) / log(2);
            c[i][j] = c[i][j ^ x] + a[i][y];
        }
    }
    if (k >= m) {
        for (int j = 0; j < m; j++) {
            sum += mx[j];
        }
        cout << sum << "\n";
        return;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < (1 << m); j++) {
            dp[i][j] = 0;
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << m); i++) {
        ll mx = 0;
        for (int j = 1; j <= n; j++) {
            mx = max(mx, c[j][i]);
        }
        dp[1][i] = mx;
        ans = max(ans, mx);
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < (1 << m); j++) {
            for (auto o: g[j]) {
                dp[i][j] = max(dp[i - 1][j ^ o] + dp[1][o], dp[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans = 0;
    for (int i = 1; i < (1 << 13); i++) {
        dfs(0, i, 0);
        // ll x=__builtin_popcount(i);
        // ans+=((1<<x)-1);
    }
    // for(int i=1;i<(1<<13);i++){
    //     ans+=g[i].size();
    // }
    // cout << ans << "\n";
    // cout << ans*130 << "\n";
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
