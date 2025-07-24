//
// Created by 27682 on 2025/7/24.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6 + 10;
constexpr int dx[3]{1, -1, 0}, dy[3]{0, 0, -1};

int n, m, k;
vi a[N], dep[N], vis[N];


inline void bfs(pii s) {
    queue<pii> q;
    q.emplace(s);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y] || a[x][y]) continue;
        vis[x][y] = 1;
        dep[x][y] = s.second;
        for (int k = 0; k < 3; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] || vis[xx][yy]) continue;
            q.emplace(xx, yy);
        }
    }
}

bool vail(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !a[x][y];
}

inline bool check() {
    queue<pii> q;
    q.emplace(1, 1);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (y + k >= m || vis[x][y] || a[x][y]) continue;
        vis[x][y] = 1;
        int xx = x, yy = y + 1;
        if (dep[xx][yy] >= y + k && dep[xx][yy] != m) return true;
        if (dep[xx][yy] == m) q.emplace(xx, yy);
        xx = x - 1, yy = y;
        if (vail(xx, yy) && !vis[xx][yy]) q.emplace(xx, yy);
        xx = x + 1, yy = y;
        if (vail(xx, yy) && !vis[xx][yy]) q.emplace(xx, yy);
    }
    return false;
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        a[i].assign(m + 1, 0);
        dep[i].assign(m + 1, 0);
        vis[i].assign(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '1';
        }
    }
    for (int j = m; j; j--) {
        for (int i = 1; i <= n; i++) {
            bfs(pii(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << dep[i][j] << ' ';
            vis[i][j] = 0;
        }
        // cout << endl;
    }
    cout << (check() ? "Yes" : "No") << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
