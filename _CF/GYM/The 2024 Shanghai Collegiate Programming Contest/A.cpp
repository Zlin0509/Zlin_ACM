//
// Created by Zlin on 2025/5/22.
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

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= m; y++) {
            int ans = 0;
            for (int xx = 0; xx <= n; xx++) {
                for (int yy = 0; yy <= m; yy++) {
                    if (xx == x && yy == y) continue;
                    int d1 = y - yy, d2 = xx - x;
                    int xxx, yyy;
                    xxx = xx + d1, yyy = yy + d2;
                    if (xxx < 0 || xxx > n || yyy < 0 || yyy > m) continue;
                    xxx = x + d1, yyy = y + d2;
                    if (xxx < 0 || xxx > n || yyy < 0 || yyy > m) continue;
                    ++ans;
                }
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
