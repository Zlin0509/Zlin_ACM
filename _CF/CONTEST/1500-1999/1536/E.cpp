//
// Created by Zlin on 2025/6/9.
//

#include "bits/stdc++.h"
#define endl "\n"
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

constexpr ll mo = 1e9 + 7;
constexpr int N = 2010;

int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int n, m;
ll val[N][N];
char mp[N][N];

inline void Zlin() {
    cin >> n >> m;
    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            val[i][j] = 1;
            if (mp[i][j] == '0') q.emplace(i, j);
        }
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
