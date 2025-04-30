//
// Created by Zlin on 2024/12/15.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vll have;
    ll tag = 1;
    while (tag <= r2) {
        have.push_back(tag);
        tag *= k;
    }
    ll ans = 0;
    for (auto x: have) {
        ll l, r;
        l = max(l1, l2 / x + (l2 % x != 0));
        r = min(r1, r2 / x);
        // cout << l << ' ' << r << '\n';
        ans += max(r - l + 1, 0ll);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
