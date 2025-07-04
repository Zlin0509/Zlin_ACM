//
// Created by Zlin on 2025/7/4.
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

int n, k, a[N], b[N], m1, m2;

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m1;
    for (int i = 1; i <= m1; i++) {
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> m2;
    for (int i = 1; i <= m2; i++) {
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
