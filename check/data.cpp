//
// Created by Zlin on 2025/2/7.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


inline void Zlin() {
    int n = rng() % (int)3e5 + 1, m = rng() % n + 1;
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; i++) cout << rng() % (int)1e3 << ' ';
    cout << endl;
    for (int i = 0; i < m; i++) cout << rng() % (int)1e3 << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    srand(time(0));
    while (ttt--) Zlin();
    return 0;
}
