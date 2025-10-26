//
// Created by Zlin on 2025/10/23.
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

inline void Zlin() {
    int n;
    cin >> n;
    vll a(n), b(n), c(n);
    for (ll &it: a) cin >> it;
    for (ll &it: b) cin >> it;
    for (ll &it: c) cin >> it;
    ll t = n - n / 2;
    sort(c.begin(), c.end());
    const auto check = [&](ll tag) {
        int cnt = 0;
        vll lx, rx;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) cnt += b[i] >= tag;
            if (a[i] > 0) {
                ll tmp = (tag - b[i]) / a[i];
                if ((tag - b[i]) % a[i]) ++tmp;
                rx.emplace_back(tmp);
            }
            if (a[i] < 0) {
                ll tmp = (tag - b[i]) / a[i];
                if ((tag - b[i]) % a[i]) --tmp;
                lx.emplace_back(tmp);
            }
        }
        sort(lx.begin(), lx.end());
        sort(rx.begin(), rx.end());
        vi cntl(n), cntr(n);
        for (const auto &it: lx) {
            int id = upper_bound(c.begin(), c.end(), it) - c.begin();
            if (id && c[id - 1] <= it) cntl[id - 1]++;
        }
        for (int i = n - 1; ~i; i--) {
            if (cntl[i]) {
                if (i) cntl[i - 1] += cntl[i] - 1;
                cntl[i] = 1;
                if (i && cntl[i - 1] == 0) cntl[i - 1] = 1, cntl[i] = 0;
            }
        }
        for (const auto &it: rx) {
            int id = lower_bound(c.begin(), c.end(), it) - c.begin();
            if (id != n) cntr[id]++;
        }
        for (int i = 0; i < n; i++) {
            if (cntr[i]) {
                if (i < n - 1) cntr[i + 1] += cntr[i] - 1;
                cntr[i] = 1;
                if (i < n - 1 && cntr[i + 1] == 0) cntr[i + 1] = 1, cntr[i] = 0;
            }
        }
        for (int i = 1; i < n; i++) cntl[i] += cntl[i - 1];
        for (int i = n - 2; ~i; i--) cntr[i] += cntr[i + 1];
        for (int i = 0; i < n - 1; i++) if (cnt + cntl[i] + cntr[i + 1] >= t) return true;
        return (cnt + cntr[0] >= t) || (cnt + cntl[n - 1] >= t);
    };
    check(25);
    ll l = -2e18, r = 2e18, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
