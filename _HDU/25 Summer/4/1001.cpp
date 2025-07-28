//
// Created by Zlin on 2025/7/28.
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

constexpr int N = 2e5 + 10;
constexpr ll mo = 998244353;

int n, a[N];
ll ans, res;

inline void Zlin() {
    ans = res = 0;
    cin >> n;
    int l = N, r = 0, L = N, R = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        if (a[i]) {
            l = min(l, i);
            r = max(r, i);
            L = min(L, a[i]);
            R = max(R, a[i]);
        }
    }
    if (ans) res = 1ll * (n - r + 1) * l % mo * (n - R + 1) % mo * (L + n + 1) % mo;
    else res = 1ll * n * (n + 1) / 2 % mo * (n + 1) % mo * (n + 1) % mo;
    cout << ans << ' ' << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
