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

ll cal(ll x) {
    ll sum = 0;
    while (x >= 3) {
        sum += x % 3 + 1;
        x /= 3;
    }
    return sum + (x == 1 ? 2 : 3);
}

inline void Zlin() {
    ll l, r, ans = 0;
    cin >> l >> r;
    vll have;
    ll rx = r;
    while (rx) {
        have.push_back(rx % 3);
        rx /= 3;
    }
    reverse(have.begin(), have.end());
    for (int i = 0; i < have.size(); i++) {
        ll x = 0;
        for (int j = 0; j < i; j++) x = x * 3 + have[j];
        x = x * 3 + have[i] - 1;
        for (int j = i + 1; j < have.size(); j++) x = x * 3 + 2;
        if (x >= l) ans = max(ans, cal(x));
    }
    cout << max({ans, cal(l), cal(r)}) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}