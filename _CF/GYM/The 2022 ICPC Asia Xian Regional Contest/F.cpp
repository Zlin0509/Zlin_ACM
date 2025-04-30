//
// Created by Zlin on 2024/10/15.
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

inline void Zlin() {
    int n, c1, c2, ans = 0;
    cin >> n >> c1 >> c2;
    char x, y, z;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z;
        if (x == y || y == z || x == z) {
            ans += min(c1, c2) + min(c1 * 2, c2);
        } else {
            ans += min(c1, c2) * 3;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}