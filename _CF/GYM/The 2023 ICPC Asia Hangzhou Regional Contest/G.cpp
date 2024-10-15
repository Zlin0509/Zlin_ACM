//
// Created by Zlin on 2024/10/15.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int cnt[3010][3010];
int idx[3010][3010];
char Map[3010][3010];
int n, m, k, fx, fy;

struct node {
    int x, y;
    int idx;

    bool operator<(const node &z) const {
        return idx > z.idx;
    }
};

int dx[4] = {0, 0, 1, -1}, dy[4]{1, -1, 0, 0};

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = k, x, y; i; i--) {
        cin >> x >> y;
        if (i == k) fx = x, fy = y;
        cnt[x][y] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> Map[i][j];
            idx[i][j] = 1e7;
        }
    priority_queue<node> q;
    q.push({fx, fy, k});
    while (!q.empty()) {
        node u = q.top();
        q.pop();
        if (idx[u.x][u.y] <= u.idx) continue;
        idx[u.x][u.y] = u.idx;
        for (int i = 0; i < 4; i++) {
            int vx = u.x + dx[i], vy = u.y + dy[i];
            if (vx < 1 || vx > n || vy < 1 || vy > m) continue;

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}