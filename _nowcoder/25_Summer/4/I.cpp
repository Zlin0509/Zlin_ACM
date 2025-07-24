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

constexpr int N = 53;
constexpr int dx[4]{0, 0, 1, -1}, dy[4]{1, -1, 0, 0};

int n, m, vis[N][N], op[N][N];
pii fa[N][N];
char mp[N][N], idx[4]{'R', 'L', 'D', 'U'};

inline bool vail(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && mp[x][y] != '#';
}

struct Op {
    int x, y, op;
};

vector<Op> ans, tmp;

inline void work() {
    while (!tmp.empty()) {
        auto [x, y, op] = tmp.back();
        int xx = x + dx[op], yy = y + dy[op];
        if (mp[x][y] == '!') {
            mp[x][y] = '*';
        } else {
            mp[x][y] = '.';
        }
        if (mp[xx][yy] == '*') {
            mp[xx][yy] = '!';
        } else {
            mp[xx][yy] = '@';
        }
        ans.emplace_back(tmp.back());
        tmp.pop_back();
    }
}

inline void bfs(int sx, int sy) {
    queue<pii> q;
    q.emplace(sx, sy);
    vis[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (mp[x][y] == '*') {
            while (x != sx || y != sy) {
                auto [fx, fy] = fa[x][y];
                tmp.emplace_back(fx, fy, op[x][y]);
                x = fx, y = fy;
                if (mp[x][y] == '!' || mp[x][y] == '@') work();
            }
            return;
        }
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if (vail(xx, yy) && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                fa[xx][yy] = {x, y};
                op[xx][yy] = k;
                q.emplace(xx, yy);
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    ans.clear(), tmp.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '@') {
                for (int ii = 1; ii <= n; ii++) {
                    for (int jj = 1; jj <= m; jj++) {
                        vis[ii][jj] = 0;
                        op[ii][jj] = -1;
                    }
                }
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '*') {
                cout << -1 << endl;
                return;
            }
        }
    }
    if (ans.size() > 100000) while (1);
    cout << ans.size() << endl;
    for (auto [x, y, c]: ans) cout << x << ' ' << y << ' ' << idx[c] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
