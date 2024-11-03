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

const ll mo = 1e9 + 7;

ll n, k;

inline void Zlin() {
    cin >> n >> k;
    ll ans = 0;
    while (k) {
        ll x = 1, sum = 1;
        while ((x << 1ll) <= k) {
            x <<= 1ll;
            sum = sum * n % mo;
        }
        k -= x;
        ans = (ans + sum) % mo;
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