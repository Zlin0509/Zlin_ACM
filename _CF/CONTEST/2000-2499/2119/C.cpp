//
// Created by 27682 on 2025/7/5.
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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1) {
        cout << l << endl;
        return;
    }
    ll z = 0;
    while (1ll << z <= l) ++z;
    if (n == 2 || 1ll << z > r) {
        cout << -1 << endl;
        return;
    }
    if (k <= n - 2) cout << l << endl;
    else cout << (1ll << z) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
