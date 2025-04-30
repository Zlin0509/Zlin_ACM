//
// Created by Zlin on 2024/10/11.
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
    int x, y, ans;
    cin >> x >> y;
    if (x == 0) {
        if (y == 0) {
            ans = 4;
        } else if (y == 1) {
            ans = 4;
        } else {
            ans = 6;
        }
    } else if (x == 1) {
        if (y == 0) {
            ans = 3;
        } else if (y == 1) {
            ans = 3;
        } else {
            ans = 4;
        }
    } else {
        if (y == 0) {
            ans = 2;
        } else if (y == 1) {
            ans = 2;
        } else {
            ans = 2;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}