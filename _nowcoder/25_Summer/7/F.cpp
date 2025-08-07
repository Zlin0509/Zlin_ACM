//
// Created by Zlin on 2025/8/5.
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

constexpr ll mo = 998244353;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) ++cnt1;
        else ++cnt2;
    }
    ll ans = 1ll * cnt1 * cnt2 % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
