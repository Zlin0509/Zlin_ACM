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
    int n = rng() % 20 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << rng() % INF + 1 << ' ';
    cout << endl;
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
