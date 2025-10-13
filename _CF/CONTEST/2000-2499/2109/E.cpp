//
// Created by 27682 on 2025/10/13.
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

constexpr ll mo = 998244353;
constexpr int N = 501;

ll dp[N][N];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int op = s[i] - '0';
        for (int j = 0; j <= k; j++) {
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
