//
// Created by 27682 on 2025/5/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


constexpr int N = 1e5 + 10;

int n;
vector<pii> line[2];

inline void Zlin() {
    line[0].clear(), line[1].clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        line[c].push_back({l, r});
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
