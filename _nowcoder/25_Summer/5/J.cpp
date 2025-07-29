//
// Created by Zlin on 2025/7/29.
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

constexpr int N = 2e5 + 10;
constexpr int INF = 1e9;
constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int n, m;
vi mp[N], dis[N];
vector<pii> s;

bool check(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

inline void bfs() {
    queue<pii> q;
    for (pii it: s) q.emplace(it), dis[it.first][it.second] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if (check(xx, yy) && dis[xx][yy] > dis[x][y] + 1) {
                dis[xx][yy] = dis[x][y] + 1;
                q.emplace(xx, yy);
            }
        }
    }
}

inline bool work(int dif) {
    int la = INF, lb = -INF, ra = INF, rb = -INF, tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dis[i][j] > dif) {
                tmp = j - i;
                la = min(la, tmp), lb = max(lb, tmp);
                tmp = j + i;
                ra = min(ra, tmp), rb = max(rb, tmp);
            }
        }
    }
    if (la == INF) return true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tmp = j - i;
            if (lb - tmp <= dif && tmp - la <= dif) {
                tmp = j + i;
                if (rb - tmp <= dif && tmp - ra <= dif) {
                    return true;
                }
            }
        }
    }
    return false;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mp[i].assign(m + 1, 0);
        dis[i].assign(m + 1, INF);
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j]) s.emplace_back(i, j);
        }
    }
    bfs();
    int l = 0, r = n + m, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (work(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
