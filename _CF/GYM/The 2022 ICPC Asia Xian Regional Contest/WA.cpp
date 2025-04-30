//
// Created by Zlin on 2024/10/17.
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

vi a(4);

inline void Zlin() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (ll i = r, rx, cnt, dif; i >= max(r - 500, l); i--) {
        rx = i, cnt = 0;
        while (rx >= 3) {
            if (rx % 3 == 0) {
                ++cnt;
                rx /= 3;
            } else {
                dif = rx % 3;
                rx -= dif;
                cnt += dif;
            }
        }
        cnt += a[rx];
        ans = max(ans, cnt);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    a[0] = 1, a[1] = 2, a[2] = 3, a[3] = 3;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}