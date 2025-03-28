//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef int i32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<i32> vi;
typedef vector<i64> vll;
typedef pair<i32, i32> pii;
typedef pair<i64, i64> pll;

constexpr int N = 1e6 + 10;

int n;
vi e[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
