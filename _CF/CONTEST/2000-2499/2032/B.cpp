//
// Created by Zlin on 2024/11/1.
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
    int n, k;
    cin >> n >> k;
    if (k == n / 2 + 1) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return;
    }
    int l = k - 1, r = n - k;
    for (int i = 1; i <= min(l, r); i++) {
        int s1 = i, s2 = i;
        int r1 = l - i + 1, r2 = r - i + 1;
        if ((r1 % 2 == 0 && r1) || (r2 % 2 == 0 && r2))
            continue;
        cout << i * 2 + 1 << '\n';
        int tag = 1;
        while (s1--) {
            cout << tag << ' ';
            tag++;
        }
        cout << k << ' ';
        tag = k + 1;
        while (s2--) {
            cout << tag << ' ';
            tag++;
        }
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}