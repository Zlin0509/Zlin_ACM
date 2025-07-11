//
// Created by 27682 on 2025/7/2.
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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
        if (a == b + 1 && a & 1) {
            cout << y << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = a + 1; i <= b; i++) {
        if (i & 1) {
            ans += min(x, y);
        } else {
            ans += x;
        }
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
