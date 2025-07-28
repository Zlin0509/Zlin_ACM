#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 305;
const int M = 20;
const ll inf = 1e9;
const ll mod = 998244353;
ll n, dp[N][N][N], d[N], fa[N];
string s;
ll a[N], r;
vector<ll> g[N];
ll inv[N], w[N];

ll q_pow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

void work_D(ll id) {
    for (int i = 1; i <= n; i++) {
        ll len = g[fa[i]].size();
        ll res = 0;
        ll len2 = g[i].size();

        if (len2 == 0) {
            for (int j = 1; j <= len; j++) {
                dp[id][i][j] = (dp[id][i][j] + dp[id - 1][i][j]) % mod;
            }
        } else {
            for (int j = 1; j <= len; j++) {
                res = (res + dp[id - 1][i][j]) % mod;
            }
            for (auto o: g[i]) {
                dp[id][o][1] = (dp[id][o][1] + res * inv[len2]) % mod;
            }
        }
    }
}

void work_L(ll id) {
    for (int i = 0; i <= n; i++) {
        if (g[i].empty()) continue;
        ll len = g[i].size();
        for (auto o: g[i]) {
            dp[id][o][1] = (dp[id - 1][o][1] + dp[id][o][1]) % mod;
        }
        for (int j = 2; j <= len; j++) {
            ll sum = 0;
            for (auto o: g[i]) {
                w[o] = dp[id - 1][o][j] * inv[len - 1] % mod;
                sum = (sum + w[o]) % mod;
            }
            for (auto o: g[i]) {
                dp[id][o][j - 1] = (dp[id][o][j - 1] + sum - w[o] + mod) % mod;
            }
        }
    }
}

void work_R(ll id) {
    for (int i = 0; i <= n; i++) {
        if (g[i].empty()) continue;
        ll len = g[i].size();
        for (auto o: g[i]) {
            dp[id][o][len] = (dp[id - 1][o][len] + dp[id][o][len]) % mod;
        }
        for (int j = 1; j < len; j++) {
            ll sum = 0;
            for (auto o: g[i]) {
                w[o] = dp[id - 1][o][j] * inv[len - 1] % mod;
                sum = (sum + w[o]) % mod;
            }
            for (auto o: g[i]) {
                dp[id][o][j + 1] = (dp[id][o][j + 1] + sum - w[o] + mod) % mod;
            }
        }
    }
}

void solve() {
    cin >> n;
    cin >> s;
    s = " " + s;
    r = 1;
    for (int i = 0; i <= n; i++) {
        d[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            ll x;
            cin >> x;
            // cout << x << " ";
            g[i].push_back(x);
            fa[x] = i;
            d[x]++;
        }
        // cout << "\n";
    }
    // for(auto o : g[1]){
    //     cout << o << " ";
    // }
    // cout << "\n";
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) r = i;
    }
    // cout << r << "\n";
    memset(dp, 0, sizeof(dp));
    fa[r] = 0;
    g[0].push_back(r);
    dp[0][r][1] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'D') {
            work_D(i);
        } else if (s[i] == 'L') {
            work_L(i);
        } else {
            work_R(i);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll len = g[fa[i]].size();
        ll res = 0;
        for (int j = 1; j <= len; j++) {
            res = (res + dp[s.size() - 1][i][j]) % mod;
        }
        res = res * i % mod;
        ans = (ans + res) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < N; i++) {
        inv[i] = q_pow(i, mod - 2);
    }
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
