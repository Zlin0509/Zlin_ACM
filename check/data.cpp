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
    int n = rng() % 5 + 1, l = rng() % int(100), h = rng() % int(100);
    cout << n << ' ' << l << ' ' << h << endl;
    for (int i = 1; i <= n; i++) cout << rng() % l + 1 << ' ' << rng() % h + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    srand(time(0));
    while (ttt--) Zlin();
    return 0;
}
