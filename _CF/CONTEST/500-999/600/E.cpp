//
// Created by 27682 on 2025/3/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef __int128 i128;
typedef long long i64;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<i64> vll;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;

constexpr int N = 1e5 + 10;

int n;
int c[N];
vi e[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
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
