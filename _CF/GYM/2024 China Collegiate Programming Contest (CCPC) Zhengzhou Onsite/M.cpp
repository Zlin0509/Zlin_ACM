//
// Created by Zlin on 2025/11/10.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 10;
constexpr ldb eps = 1e-15;

ll mx = 2e9, idx = 0;
ll n, k, a[N];

inline ldb cal(ldb base, int id) {
    ldb res = base * a[id] / (a[idx] + (a[id] - a[idx]) * base);
    return res;
}

inline ldb cal(ldb base) {
    ldb sum = 0;
    for (int i = 1; i <= n; i++) sum += cal(base, i);
    return sum;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < mx) {
            mx = a[i];
            idx = i;
        }
    }
    ldb l = 0, r = 1, mid;
    while (abs(r - l) > eps) {
        mid = (l + r) / 2.0l;
        if (cal(mid) > k + eps) r = mid;
        else l = mid;
    }
    for (int i = 1; i <= n; i++) cout << fixed << setprecision(12) << cal(l, i) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
