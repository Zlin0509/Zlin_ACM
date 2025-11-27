//
// Created by Zlin on 2025/11/27.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*

1
6
4 6 4 1 6 1

 */

const int N = 5e5 + 7;
ll a[N], n, p[105];
const int bit = 61;
int cnt;

bool insert(ll x) {
    for (int i = bit; i >= 0; i--) {
        if (x & (1ll << i)) {
            if (!p[i]) {
                p[i] = x, cnt++;
                return true;
            }
            x ^= p[i];
        }
    }
    return false;
}


ll askmx(ll base) {
    ll ans = 0;
    for (ll i = bit; i >= 0; i--)
        if (((ans ^ p[i]) & base) > ans) {
            ans = (ans ^ p[i]) & base;
        }
    return ans;
}

inline void Zlin() {
    cnt = 0;
    for (int i = 0; i <= bit; i++) p[i] = 0;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans ^= a[i];
        insert(a[i]);
    }
    ll base = 0;
    for (int i = 60; ~i; i--) {
        if (ans >> i & 1) {
            if (p[i]) insert(p[i] - (1ll << i));
            p[i] = 0;
        } else base += 1ll << i;
    }
    cout << max(ans, askmx(base)) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
