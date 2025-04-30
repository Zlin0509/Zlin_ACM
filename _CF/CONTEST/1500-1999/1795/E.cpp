//
// Created by 27682 on 2025/4/22.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    ll ans = 0;
    for (int &it: a) cin >> it, ans += it;
    stack<pii> have;
    have.push({a[0], a[0]});
    vll dpl(n), dpr(n);
    dpl[0] = dpr[n - 1] = 0;
    for (int i = 1, l, r, len; i < n; i++) {
        ll val = 0;
        l = r = a[i];
        while (!have.empty() && have.top().second >= l) {
            auto [lx, rx] = have.top();
            have.pop();
            len = rx - lx + 1;
            if (l > len) {
                val += 1ll * len * (rx - l + 1);
                l -= len;
            } else {
                val += 1ll * (l - 1) * (rx - l + 1);
                val += 1ll * (lx * 2 + len - l) * (len - l + 1) / 2;
                l = 1;
            }
        }
        have.push({l, r});
        dpl[i] = dpl[i - 1] + val;
    }
    while (!have.empty()) have.pop();
    have.push({a[n - 1], a[n - 1]});
    for (int i = n - 2, l, r, len; ~i; i--) {
        ll val = 0;
        l = r = a[i];
        while (!have.empty() && have.top().second >= l) {
            auto [lx, rx] = have.top();
            have.pop();
            len = rx - lx + 1;
            if (l > len) {
                val += 1ll * len * (rx - l + 1);
                l -= len;
            } else {
                val += 1ll * (l - 1) * (rx - l + 1);
                val += 1ll * (lx * 2 + len - l) * (len - l + 1) / 2;
                l = 1;
            }
        }
        have.push({l, r});
        dpr[i] = dpr[i + 1] + val;
    }
    for (int i = 0; i < n; i++) ans = min(ans, a[i] + dpl[i] + dpr[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
