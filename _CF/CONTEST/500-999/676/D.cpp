//
// Created by 27682 on 2025/6/30.
//
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m, mp[1010][1010], dis[4][1010][1010], vis[4][1010][1010];
int sx, sy, tx, ty;

// (1 << 3) 左边
// (1 << 2) 上面
// (1 << 1) 右边
// (1 << 0) 下面

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            mp[i][j] = c;
            for (int k = 0; k < 4; k++) dis[k][i][j] = INF;
            if (mp[i][j] == '+') mp[i][j] = (1 << 4) - 1;
            else if (mp[i][j] == '-') mp[i][j] = (1 << 3) + (1 << 1);
            else if (mp[i][j] == '|') mp[i][j] = (1 << 2) + (1 << 0);
            else if (mp[i][j] == '<') mp[i][j] = 1 << 3;
            else if (mp[i][j] == '^') mp[i][j] = 1 << 2;
            else if (mp[i][j] == '>') mp[i][j] = 1 << 1;
            else if (mp[i][j] == 'v') mp[i][j] = 1 << 0;
            else if (mp[i][j] == 'L') mp[i][j] = (1 << 4) - 1 - (1 << 3);
            else if (mp[i][j] == 'R') mp[i][j] = (1 << 4) - 1 - (1 << 1);
            else if (mp[i][j] == 'U') mp[i][j] = (1 << 4) - 1 - (1 << 2);
            else if (mp[i][j] == 'D') mp[i][j] = (1 << 4) - 1 - (1 << 0);
            else mp[i][j] = 0;
        }
    }
    cin >> sx >> sy >> tx >> ty;
    --sx, --sy, --tx, --ty;
    dis[0][sx][sy] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > q;
    q.push({dis[0][sx][sy], sx * m + sy, 0});
    while (!q.empty()) {
        int idx = get<1>(q.top()), tmp = get<2>(q.top());
        q.pop();
        int x = idx / m, y = idx % m, xx, yy, ux, vx;
        if (vis[tmp][x][y]) continue;
        vis[tmp][x][y] = 1;
        xx = x - 1, yy = y;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            ux = mp[x][y], vx = mp[xx][yy];
            for (int i = 0; i < tmp; i++) {
                ux |= (ux & 1 << i) << 4;
                vx |= (vx & 1 << i) << 4;
            }
            ux >>= tmp, vx >>= tmp;
            int val = INF;
            for (int i = 0; i < 4; i++) {
                if (ux >> 2 & 1 && vx >> 0 & 1) {
                    val = i;
                    break;
                }
                ux |= (ux & 1) << 4, vx |= (vx & 1) << 4;
                ux >>= 1, vx >>= 1;
            }
            if (dis[(tmp + val) % 4][xx][yy] > dis[tmp][x][y] + val + 1) {
                dis[(tmp + val) % 4][xx][yy] = dis[tmp][x][y] + val + 1;
                q.push({dis[(tmp + val) % 4][xx][yy], xx * m + yy, (tmp + val) % 4});
            }
        }
        xx = x + 1, yy = y;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            ux = mp[x][y], vx = mp[xx][yy];
            for (int i = 0; i < tmp; i++) {
                ux |= (ux & 1 << i) << 4;
                vx |= (vx & 1 << i) << 4;
            }
            ux >>= tmp, vx >>= tmp;
            int val = INF;
            for (int i = 0; i < 4; i++) {
                if (ux >> 0 & 1 && vx >> 2 & 1) {
                    val = i;
                    break;
                }
                ux |= (ux & 1) << 4, vx |= (vx & 1) << 4;
                ux >>= 1, vx >>= 1;
            }
            if (dis[(tmp + val) % 4][xx][yy] > dis[tmp][x][y] + val + 1) {
                dis[(tmp + val) % 4][xx][yy] = dis[tmp][x][y] + val + 1;
                q.push({dis[(tmp + val) % 4][xx][yy], xx * m + yy, (tmp + val) % 4});
            }
        }
        xx = x, yy = y + 1;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            ux = mp[x][y], vx = mp[xx][yy];
            for (int i = 0; i < tmp; i++) {
                ux |= (ux & 1 << i) << 4;
                vx |= (vx & 1 << i) << 4;
            }
            ux >>= tmp, vx >>= tmp;
            int val = INF;
            for (int i = 0; i < 4; i++) {
                if (ux >> 1 & 1 && vx >> 3 & 1) {
                    val = i;
                    break;
                }
                ux |= (ux & 1) << 4, vx |= (vx & 1) << 4;
                ux >>= 1, vx >>= 1;
            }
            if (dis[(tmp + val) % 4][xx][yy] > dis[tmp][x][y] + val + 1) {
                dis[(tmp + val) % 4][xx][yy] = dis[tmp][x][y] + val + 1;
                q.push({dis[(tmp + val) % 4][xx][yy], xx * m + yy, (tmp + val) % 4});
            }
        }
        xx = x, yy = y - 1;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
            ux = mp[x][y], vx = mp[xx][yy];
            for (int i = 0; i < tmp; i++) {
                ux |= (ux & 1 << i) << 4;
                vx |= (vx & 1 << i) << 4;
            }
            ux >>= tmp, vx >>= tmp;
            int val = INF;
            for (int i = 0; i < 4; i++) {
                if (ux >> 3 & 1 && vx >> 1 & 1) {
                    val = i;
                    break;
                }
                ux |= (ux & 1) << 4, vx |= (vx & 1) << 4;
                ux >>= 1, vx >>= 1;
            }
            if (dis[(tmp + val) % 4][xx][yy] > dis[tmp][x][y] + val + 1) {
                dis[(tmp + val) % 4][xx][yy] = dis[tmp][x][y] + val + 1;
                q.push({dis[(tmp + val) % 4][xx][yy], xx * m + yy, (tmp + val) % 4});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) ans = min(ans, dis[i][tx][ty]);
    cout << (ans == INF ? -1 : ans) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
