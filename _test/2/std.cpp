#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 2e5 + 5;
const ll mod = 998244353;
const ll inf = 1e18;
ll n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll cnt1 = 0, cnt2 = 0;
    for (int i = n; i >= 1; i--) {
        a[i] = a[i] - a[i - 1];
        if (a[i] > 0) {
            cnt1 += a[i];
        } else {
            cnt2 -= a[i];
        }
    }
    cout << max(cnt1, cnt2) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}