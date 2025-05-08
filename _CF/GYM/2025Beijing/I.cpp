#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e14;
const ll M = 1e18;
const __int128 inf = 1e36;
ll a, b, k;

inline ll get(ll k, ll a) {
    if (k / a == 0) return M;
    return k / (k / a);
}

inline void work1(int g, ll &ans) {
    ll xx = ceil(a * 1.0 / g), yy = ceil(b * 1.0 / g);
    if (xx * g - a <= k && yy * g - b <= k) {
        ans = min(ans, xx * g * yy);
    }
}

inline void work2(ll g, __int128 &ans) {
    __int128 xx = ceil(a * 1.0 / g), yy = ceil(b * 1.0 / g);
    if (xx * g - a <= k && yy * g - b <= k) {
        ans = min(ans, xx * g * yy);
    }
}

void solve() {
    cin >> a >> b >> k;
    if (a > b) swap(a, b);
    if (b > 1e5) {
        __int128 ans = inf;
        for (ll l = 1; l <= b;) {
            ll r = min(b, min(get(a, l), get(b, l)));
            work2(l, ans);
            work2(r, ans);
            l = r + 1;
        }
        stack<int> stk;
        while (ans) {
            stk.push(ans % 10);
            ans /= 10;
        }
        while (stk.size()) {
            cout << stk.top();
            stk.pop();
        }
        cout << "\n";
    } else {
        ll ans = 1e18;
        for (int l = 1; l <= b;) {
            int r = min(b, min(get(a, l), get(b, l)));
            work1(l, ans);
            work1(r, ans);
            l = r + 1;
        }
        cout << ans << "\n";
    }
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
