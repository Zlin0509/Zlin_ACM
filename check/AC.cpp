#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 21;
const ll inf = 2e9;
const ll mod = 998244353;
ll n, a[N], q, b[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = (b[i - 1] + a[i] + 1) >> 1;
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll id = n - y + 1;
        ll idx = upper_bound(a, a + 1 + n, x) - a;
        if (idx > id) {
            cout << "0\n";
        } else {
            ll ans = 0;
            for (int i = idx; i <= id; i++) {
                ll len = (a[i] - x + 1) / 2;
                x += len;
                ans += len;
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
