#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
using ull = unsigned long long;
const int N = 101;
const int MAXN = 2e5 + 5;
const int M = 4e6 + 5;
const ll mod = 998244353;
const ll inf = 1e9;
const ull base = 131;
const double eps = 1e-3;
ll dp[100];
ll a[N];

ll q_pow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

void solve() {
    for (int i = 1; i <= 9; i++) cin >> a[i];
    if (a[2] >= a[1]) {
        a[3] += a[1];
        a[2] -= a[1];
        a[1] = 0;
    } else {
        a[3] += a[2];
        a[1] -= a[2];
        a[2] = 0;
    }
    ll ans = 1;
    if (a[1] == 1) {
        for (int i = 2; i <= 9; i++) {
            if (a[i]) {
                a[i]--;
                ans *= i + 1;
                a[1] = 0;
                break;
            }
        }
    }
    for (int i = 2; i <= 9; i++) {
        ans = ans * q_pow(i, a[i]) % mod;
    }
    ans = dp[a[1]] % mod * ans % mod;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i < N; i++) {
        dp[i] = max(dp[i - 1] + 1, dp[i - 2] * 2);
        dp[i] = max(dp[i], dp[i - 3] * 3);
        cout << i << ' ' << dp[i] << "\n";
    }
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
