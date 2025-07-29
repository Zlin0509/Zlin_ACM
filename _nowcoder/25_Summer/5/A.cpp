//
// Created by Zlin on 2025/7/29.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 200;
constexpr ll INF = 1e16;

ll n, k, s, t, dif;

ll ans;

inline void Zlin() {
    cin >> n >> k >> s >> t;
    if (n == k) {
        if (s == t) cout << 0 << endl;
        else if (s + t == n) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    if (s == t) {
        cout << 0 << endl;
        return;
    }
    if (k % 2 == 0 && (s & 1) != (t & 1)) {
        cout << -1 << endl;
        return;
    }
    ans = INF;
    if (k & 1) {
        dif = min(k, n - k);
        if ((s & 1) == (t & 1)) {
            ans = abs(t - s) / 2;
            ans = (ans + dif - 1) / dif * 2;
        } else {
            ll res, lx = t + k - min(k, t) * 2, rx = t + k - max(0ll, k - (n - t)) * 2;
            if (lx <= s && rx >= s) ans = 1;
            res = abs(lx - s) / 2;
            res = (res + dif - 1) / dif * 2 + 1;
            ans = min(ans, res);
            res = abs(rx - s) / 2;
            res = (res + dif - 1) / dif * 2 + 1;
            ans = min(ans, res);
        }
    } else {
        if (k <= n / 2) {
            dif = k / 2;
            ll res, lx = t + k - min(k, t) * 2, rx = t + k - max(0ll, k - (n - t)) * 2;
            if (lx <= s && rx >= s) ans = 1;
            res = abs(lx - s) / 2;
            res = (res + dif - 1) / dif + 1;
            ans = min(ans, res);
            res = abs(rx - s) / 2;
            res = (res + dif - 1) / dif + 1;
            ans = min(ans, res);
        } else {
            dif = n - k;
            ll res, lx = t + k - min(k, t) * 2, rx = t + k - max(0ll, k - (n - t)) * 2;
            if (lx <= s && rx >= s) ans = 1;
            res = abs(lx - s) / 2;
            res = (res + dif - 1) / dif * 2 + 1;
            ans = min(ans, res);
            res = abs(rx - s) / 2;
            res = (res + dif - 1) / dif * 2 + 1;
            ans = min(ans, res);
            res = abs(s - t) / 2;
            res = (res + dif - 1) / dif * 2;
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
