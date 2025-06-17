//
// Created by Zlin on 2025/6/9.
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

constexpr ll mo = 1e9 + 7;
constexpr int N = 2010;


inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    ll ans = 1;
    bool tag = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '0') tag = true;
            else ans = ans * 2 % mo;
        }
    }
    if (!tag) ans = (ans + mo - 1) % mo;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
