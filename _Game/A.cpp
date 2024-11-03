//
// Created by Zlin on 2024/11/3.
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
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 0 << '\n';
        return;
    }
    vi a;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    if (a.back() % 2 == 0) {
        cout << 1 << '\n';
        return;
    }
    for (auto it: a)
        if (it % 2 == 0) {
            cout << 2 << '\n';
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