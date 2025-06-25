//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef vector<ll> vll;

constexpr int N = 5e5 + 10;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vll c(n), val(n), idx(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) cin >> c[i], idx[i] = rng();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        --u, --v;
        val[v] += idx[u];
    }
    for (int i = 0; i < n; i++) mp[val[i]] += c[i];
    ll ans = 0;
    for (auto &[k, v]: mp) if (k) ans = ans ? gcd(ans, v) : v;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
