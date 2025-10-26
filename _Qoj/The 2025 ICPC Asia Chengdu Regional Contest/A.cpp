//
// Created by Zlin on 2025/10/26.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int dif = 1e6;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] *= dif;
        sum += a[i];
    }
    if (sum > 100 * dif) {
        int res = sum - 100 * dif;
        for (int &it: a) {
            if (it) {
                int k = min(res, dif / 2);
                res -= k, it -= k;
            }
        }
        if (res) {
            cout << "No" << endl;
            return;
        }
    } else {
        int res = 100 * dif - sum;
        for (int &it: a) {
            int k = min(res, dif / 2 - 1);
            res -= k, it += k;
        }
        if (res) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for (int &it: a) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
