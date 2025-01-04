//
// Created by 27682 on 2024/12/31.
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
    ll n = 9, ans = 2025;
    while (1) {
        ++n;
        ans += pow(n, 3);
        ll x = ans / 100, y = ans % 100;
        if (ans == (x + y) * (x + y)) break;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}