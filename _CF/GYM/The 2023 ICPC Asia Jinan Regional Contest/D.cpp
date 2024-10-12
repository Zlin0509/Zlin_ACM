//
// Created by Zlin on 2024/10/8.
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

inline void Zlin() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = a + c, y = b + d - x, ans = 0, xx;
    while (x) {
        xx = x % 10;
        x /= 10;
        ans = max(ans, min(9ll, xx + y));
        y /= 10;
        if (ans == 9) break;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}