//
// Created by 27682 on 2025/5/22.
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

constexpr int N = 2001;

int dx[4]{0, 0, 1, -1}, dy[4]{1, -1, 0, 0};

int n, m;
int mp[N][N], val[N][N], vis[N][N];


inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'R') mp[i][j] = 0;
            if (c == 'L') mp[i][j] = 1;
            if (c == 'D') mp[i][j] = 2;
            if (c == 'U') mp[i][j] = 3;
            val[i][j] = vis[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                vector<pii> stk;
            }
        }
    }
    int ans = 0;
    pii pos;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans < val[i][j]) {
                pos = {i, j};
                ans = val[i][j];
            }
        }
    }
    cout << pos.first << " " << pos.second << ' ' << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
