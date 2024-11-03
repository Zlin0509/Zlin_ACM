//
// Created by Zlin on 2024/11/3.
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

ll k, x;

bool check(ll z) {
    return (1 + z) * z / 2ll >= x;
}

bool check1(ll z) {
    return (k - 1 + k - z) * z / 2ll >= x;
}

inline void Zlin() {
    cin >> k >> x;
    ll tag = (1 + k) * k / 2ll;
    ll ans = 0;
    if (x < tag) {
        ll l = 0, r = k, mid;
        while (l < r) {
            mid = (l + r) / 2ll;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        ans += l;
    } else {
        x -= tag;
        ans += k;
        ll l = 0, r = k - 1, mid;
        while (l < r) {
            mid = (l + r) / 2ll;
            if (check1(mid)) r = mid;
            else l = mid + 1;
        }
        ans += l;
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