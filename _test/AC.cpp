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
    ll sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += i;
        if (sum >= x) {
            cout << i << '\n';
            return;
        }
    }
    for (int i = 1; i <= k - 1; i++) {
        sum += k = i;
        if (sum >= x) {
            cout << k + i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}