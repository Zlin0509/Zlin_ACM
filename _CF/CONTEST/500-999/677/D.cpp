//
// Created by Zlin on 2025/7/4.
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

constexpr int N = 1e5;

int n, m, p, mp[301][301], dis[2][301][301];
vector<pii> idx[N], now;

inline int cal(int x, int y, int xx, int yy) {
    return abs(x - xx) + abs(y - yy);
}

inline void Zlin() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            idx[mp[i][j]].emplace_back(i, j);
            dis[0][i][j] = dis[1][i][j] = 1e9;
        }
    }
    for (auto [x, y]: idx[1]) {
        dis[1][x][y] = cal(x, y, 1, 1);
        now.emplace_back(x, y);
    }
    for (int k = 1; k < p; k++) {
        for (auto [x, y]: now) dis[k & 1 ^ 1][x][y] = 1e9;
        for (auto [x, y]: now) {
            for (auto [xx, yy]: idx[k + 1]) {
                dis[k & 1 ^ 1][xx][yy] = min(dis[k & 1 ^ 1][xx][yy], dis[k & 1][x][y] + cal(x, y, xx, yy));
                dis[k & 1 ^ 1][x][y] = min(dis[k & 1 ^ 1][x][y], dis[k & 1][x][y] + cal(x, y, xx, yy));
            }
        }
        for (auto [x, y]: idx[k + 1]) now.emplace_back(x, y);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << dis[k & 1 ^ 1][i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans = min(ans, dis[p & 1][i][j]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
