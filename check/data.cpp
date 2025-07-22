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

constexpr int N = 10;

constexpr ll INF = 32;

inline void Zlin() {
    cout << rng() % (1 << 31) << ' ' << rng() % (1 << 31) << ' ' << rng() % (1 << 31) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    srand(time(0));
    cout << 1 << endl;
    while (ttt--) Zlin();
    return 0;
}
