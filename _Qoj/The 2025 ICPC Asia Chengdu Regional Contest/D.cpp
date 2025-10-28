//
// Created by Zlin on 2025/10/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// a, b, k还剩几颗球, op谁在打球, tp当前打进什么球;
int dp[148][148][22][2][2];

inline void Zlin() {
}

inline void work() {

    for (int k = 21; ~k; k--) {
        for (int op = 0; op < 2; op++) {
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    work();
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
