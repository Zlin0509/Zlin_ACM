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

const int N = 10;

inline void Zlin() {
    int n = random() % N + 1;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        a[i] = random();
        c[i] = random();
        b[i] = random() % n + 1;
    }
    cout << n << '\n';
    for (auto it: a) cout << it << ' ';
    cout << '\n';
    for (auto it: b) cout << it << ' ';
    cout << '\n';
    for (auto it: c) cout << it << ' ';
    cout << '\n';
}

int main() {
    srand(time(0));
    int ttt = 1;
    while (ttt--) Zlin();
}