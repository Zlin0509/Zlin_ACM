//
// Created by 27682 on 2025/4/10.
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
    int n;
    string s;
    cin >> s;
    n = s.length();
    s = ' ' + s;
    int dp[2][n + 1][n * n * 2];
    memset(dp, 200, sizeof(dp));
    dp[0][0][n * n] = 0;
    for (int i = 1, o = 0; i <= n; i++, o ^= 1) {
        memset(dp[o], 200, sizeof(dp[o]));
        for (int j = 0; j <= i; j++) {
            for (int k = -n * n; k <= n * n; k++) {
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
