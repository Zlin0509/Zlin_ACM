//
// Created by Zlin on 2025/5/11.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll x, y, z, k, ans;

inline void Zlin() {
    cin >> x >> y >> z >> k;
    ans = 2e18;
    ll sum = 0, tot = 0, base = 0;
    while (sum < z) {
        ll dif = z - sum, res;
        for (int l = base + 1, r; l <= base + k && l <= z;) {
            r = ceil(1.0 * dif / l);
            res = (l - base) * x + r * y;
            ans = min(ans, tot + res);
            if (r <= 1) break;
            r = ceil(1.0 * dif / (r - 1));
            l = r;
        }
        tot += k * x + y;
        sum += base += k;
    }
    ans = min(ans, tot);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
