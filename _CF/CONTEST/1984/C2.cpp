//
// Created by Zlin on 2024/8/31.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const ll mo = 998244353;
ll pd[200010]{};

inline void Zlin() {
    ll n, mn = INT_MAX;
    cin >> n;
    vector<ll> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i], mn = min(mn, sum[i]);
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] >= 0) ++cnt;
        if (sum[i] == mn && mn < 0) ans = (ans + pd[cnt + n - i]) % mo;
    }
    if (mn >= 0) ans = pd[cnt];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    pd[0] = 1;
    for (int i = 1; i <= 200001; i++) pd[i] = pd[i - 1] * 2 % mo;
    while (ttt--) Zlin();
}