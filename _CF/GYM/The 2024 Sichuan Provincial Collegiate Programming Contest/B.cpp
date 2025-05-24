//
// Created by Zlin on 2025/5/24.
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


inline void Zlin() {
    vll a(6);
    for (int i = 1; i < 6; i++) cin >> a[i];
    ll ans = 0, tmp;
    tmp = min(a[5], a[1]);
    ans += tmp;
    a[5] -= tmp, a[1] -= tmp;
    tmp = min(a[4], a[2]);
    ans += tmp;
    a[4] -= tmp, a[2] -= tmp;
    tmp = min(a[4], a[1] / 2);
    ans += tmp;
    a[4] -= tmp, a[1] -= tmp * 2;
    tmp = a[3] / 2;
    ans += tmp;
    a[3] -= tmp * 2;
    tmp = min({a[3], a[2], a[1]});
    ans += tmp;
    a[3] -= tmp, a[2] -= tmp, a[1] -= tmp;
    tmp = min({a[3], a[1] / 3});
    ans += tmp;
    a[3] -= tmp, a[1] -= tmp * 3;
    tmp = a[2] / 3;
    ans += tmp;
    a[2] -= tmp * 3;
    tmp = min({a[2], a[1] / 4});
    ans += tmp;
    a[2] -= tmp, a[1] -= tmp * 4;
    tmp = a[1] / 6;
    ans += tmp;
    a[1] -= tmp * 6;
    ll all = 0;
    for (int i = 1; i < 6; i++) all += a[i];
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
