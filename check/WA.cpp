#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 21;
const ll inf = 2e9;
const ll mod = 998244353;
ll n, a[N], q;
ll b[N], d0[N], d1[N];
bool vis[N];

void solve() {
    cin >> n >> q;
    ll op0 = -1, op1 = -1;
    d0[0] = d1[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = (b[i - 1] + a[i]) / 2;
        vis[i] = (b[i - 1] + a[i]) & 1;
        if (vis[i]) op1 = i;
        else op0 = i;
        d0[i] = op0, d1[i] = op1;
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll id = n - y + 1;
        ll idx = upper_bound(a, a + 1 + n, x) - a;
        if (idx > id) {
            cout << "0\n";
        } else {
            if (id - idx + 1 < 000) {
                ll ans = 0;
                for (int i = idx; i <= id; i++) {
                    ll len = (a[i] - x + 1) / 2;
                    x += len;
                    ans += len;
                }
                cout << ans << "\n";
            } else {
                ll ret = 0;
                for (int i = 32; i >= 0; i--) {
                    if (x >> i & 1) {
                        if (idx + i >= d0[id]) {
                            ret = 1;
                            break;
                        }
                    }
                }
                cout << b[id] + 1 - x + ret << "\n";
            }
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
