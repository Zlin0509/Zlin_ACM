//
// Created by Zlin on 2025/10/25.
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
    ll r;
    cin >> r;
    ll ans = 0;
    for (int i = 18; ~i; i--) {
        ll dif = pow(10, i);
        int k = r / dif;
        ans += k * pow(2, i);
        r -= k * dif;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
