//
// Created by 27682 on 2025/7/25.
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

ll a[14], sum, base;

inline void Zlin() {
    sum = base = 0;
    for (int i = 1; i <= 13; i++) cin >> a[i];
    while (1) {
        int check = 0, idx = 1;
        sort(a + 1, a + 14, greater());
        for (int i = 1; i <= 13; i++) {
            if (a[i] % 3 == 0 && a[i] >= 3) {
                idx = i;
                break;
            }
        }
        for (int i = 1; i <= 13; i++) {
            if (a[i] % 3 && i != idx) {
                check = i;
                break;
            }
        }
        if (a[idx] < 3 || a[check] < 1) break;
        a[idx] -= 3;
        a[check] -= 1;
        ++base;
    }
    sort(a + 1, a + 14);
    for (int i = 1; i <= 12; i++) sum += a[i];
    if (sum <= a[13] / 3) cout << sum + base << endl;
    else {
        for (int i = 1; i <= 12; i++) {
            if (a[i] % 3) {
                cout << base << endl;
                return;
            }
        }
        cout << (sum + a[13]) / 4 + base << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
