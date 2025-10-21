//
// Created by 27682 on 2025/10/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using T = ll;

constexpr ldb PI = 3.1415926535897932384l;

ldb ang[400007];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        ang[i] = atan2(y, x);
    }
    sort(ang, ang + n);
    for (int i = 0; i < n; i++) ang[i + n] = ang[i] + 2 * PI;
    ldb ans = 0;
    for (int i = k; i < n << 1; i++) ans = max(ans, ang[i] - ang[i - k]);
    cout << fixed << setprecision(10) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
