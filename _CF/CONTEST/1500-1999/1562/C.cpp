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

inline void Zlin() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = n / 2 + 1; i <= n; i++) {
        if (s[i] == '0') {
            cout << 1 << ' ' << i << ' ' << 1 << ' ' << i - 1 << endl;
            return;
        }
    }
    for (int i = n - n / 2; i; i--) {
        if (s[i] == '0') {
            cout << i << ' ' << n << ' ' << i + 1 << ' ' << n << endl;
            return;
        }
    }
    cout << 1 << ' ' << n / 2 << ' ' << n - n / 2 + 1 << ' ' << n << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
