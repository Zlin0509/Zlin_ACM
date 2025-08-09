//
// Created by Zlin on 2025/8/8.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vll a, b, c, sa, sb, sc;

inline ll cal1(ll base1, ll base2) {
    ll base3 = -base1 - base2, res = 0, pos;
    pos = lower_bound(b.begin(), b.end(), base2) - b.begin();
    if (pos != n) res += sb[pos] - base2 * (n - pos);
    pos = lower_bound(c.begin(), c.end(), base3) - c.begin();
    if (pos != n) res += sc[pos] - base3 * (n - pos);
    return res;
}

inline ll cal(ll base1) {
    ll res = 0, pos;
    pos = lower_bound(a.begin(), a.end(), base1) - a.begin();
    if (pos != n) res += sa[pos] - base1 * (n - pos);
    int l = -1e9, r = 1e9;
    while (l + 2 < r) {
        int lx = l + (r - l) / 3, rx = r - (r - l) / 3;
        ll rsl = cal1(base1, lx), rsr = cal1(base1, rx);
        if (rsl < rsr) r = rx;
        else l = lx;
    }
    ll tmp = 1e18;
    for (int i = l; i <= r; i++) tmp = min(tmp, cal1(base1, i));
    return res + tmp;
}

inline void read() {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    sa.assign(n, 0);
    sb.assign(n, 0);
    sc.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
}

inline void Zlin() {
    read();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sa[n - 1] = a[n - 1];
    sb[n - 1] = b[n - 1];
    sc[n - 1] = c[n - 1];
    for (int i = n - 2; ~i; i--) {
        sa[i] = a[i] + sa[i + 1];
        sb[i] = b[i] + sb[i + 1];
        sc[i] = c[i] + sc[i + 1];
    }
    ll ans = 1e18;
    int l = -1e9, r = 1e9;
    while (l + 2 < r) {
        int lx = l + (r - l) / 3, rx = r - (r - l) / 3;
        ll rsl = cal(lx), rsr = cal(rx);
        if (rsl > rsr) l = lx;
        else r = rx;
    }
    for (int i = l; i <= r; i++) ans = min(ans, cal(i));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
