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

inline void Zlin() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll l = 0, r = 32, mid;
    auto check = [&](int x) {
        ll sum = 1ll << x;
        return sum >= c;
    };
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    ll ans = l * a + b, cnt, sum;
    for (int i = 0; i < l; i++) {
        cnt = 1ll << i;
        sum = a * i + b * ceil((double) c / cnt);
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}