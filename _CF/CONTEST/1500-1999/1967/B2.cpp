//
// Created by 27682 on 2025/4/7.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    // for (int k = 1; k <= n; k++) {
    //     for (int a = 1; a <= n; a++) {
    //         for (int b = 1; b <= m; b++) {
    //             if (b * gcd(a, b) == k * (a + b)) {
    //                 cout << k << ' ' << a << ' ' << b << endl;
    //                 ++ans;
    //             }
    //         }
    //     }
    //     cout << endl;
    // }
    for (int a = 1; a <= n / a; ++a) {
        for (int b = 1; b <= m / b; ++b) {
            if (gcd(a, b) == 1) ans += min(n / a, m / b) / (a + b);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
