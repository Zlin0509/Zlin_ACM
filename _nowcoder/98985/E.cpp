#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 2e5 + 50;
const ll M = 1e6 + 5;
const ll inf = 1e18;
const ll mod = 998244353;
ll n, a[20];
string t;

void solve() {
    cin >> t;
    ll x = 0;
    ll ans1 = 10, ans2 = 10;
    for (int k = 0; k < 9; k++) {
        x += (t[k] - '0') * (1ll << k);
    }
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 9; i++) {
        string t;
        cin >> t;
        ll x = 0;
        for (int k = 0; k < 9; k++) {
            if (t[k] == '1') {
                a[k] |= (1ll << i);
            }
        }
    }
    for (int S = 0; S < (1 << 9); S++) {
        ll y = x ^ S, res = 0;
        for (int i = 0; i < 9; i++) {
            if (a[i] && (a[i] & y) == a[i]) res++;
        }
        ll cnt = __builtin_popcount(S);
        if (res == 9) {
            ans1 = min(ans1, cnt);
        } else if (res == 0) {
            ans2 = min(ans2, cnt);
        }
    }
    if (ans1 == 10) ans1 = -1;
    if (ans2 == 10) ans2 = -1;
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}