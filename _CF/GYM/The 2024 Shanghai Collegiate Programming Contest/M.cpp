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
    int n, ans = 0, len = 1;
    cin >> n;
    for (int d = 2; d <= n; d++) {
        int tmp = min(n / d * (d - 1) + max(n % d - 1, 0), n - d);
        if (tmp > ans) {
            ans = tmp;
            len = d;
        }
    }
    int k = n / len;
    int cnt = 0;
    cout << ans << endl;
    for (int i = 1; i <= n * k; i += len) {
        for (int j = 1; j < len && cnt < ans; j++) {
            if (cnt == ans) break;
            ++cnt;
            cout << i + j - 1 << ' ' << i + j << endl;
        }
    }
    while (cnt < ans) {
        ++cnt;
        cout << cnt << ' ' << cnt + 1 << endl;
    }
    for (int i = 1; i <= ans; i++) cout << i << ' ' << i + len << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
