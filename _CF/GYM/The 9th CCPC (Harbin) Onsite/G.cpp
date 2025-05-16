//
// Created by Zlin on 2025/5/16.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

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

int n, m, k;

struct Line {
    int lx, rx, id;
};

vector<Line> line[N], have[N];

vi e[N << 1];

bool check(Line a, Line b) {
    if ((b.lx - a.lx) * (b.rx - a.rx) <= 0) return true;
    return false;
}

int vis[N << 1];

inline bool dfs(int u, int fa) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        if (vis[v] || !dfs(v, u)) return false;
    }
    return true;
}

inline void Zlin() {
    cin >> n >> m >> k;
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    if (m > k * 2 + 1) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= k; i++) {
        Line s;
        int y;
        cin >> s.lx >> s.rx >> y;
        line[y].push_back(s);
    }
    for (int i = 1, tot = 0; i <= m; i++) {
        if (line[i].empty()) {
            have[i].push_back({1, n, ++tot});
        } else {
            Line s;
            auto [lx, rx, id] = *line[i].begin();
            if (lx != 1) {
                s = {1, lx - 1, ++tot};
                have[i].push_back(s);
            }
            for (int j = 1; j < line[i].size(); j++) {
                if (rx + 1 <= line[i][j].lx - 1) {
                    s = {rx + 1, line[i][j].lx - 1, ++tot};
                    have[i].push_back(s);
                }
                lx = line[i][j].lx, rx = line[i][j].rx;
            }
            if (rx != n) {
                s = {rx + 1, n, ++tot};
                have[i].push_back(s);
            }
        }
    }
    for (int i = 1; i < m; i++) {
        auto lx = have[i].begin(), rx = have[i + 1].begin();
        while (lx != have[i].end() && rx != have[i + 1].end()) {
            if (check(*lx, *rx)) {
                e[lx->id].push_back(rx->id);
                e[rx->id].push_back(lx->id);
            }
        }
    }
    if (!dfs(1, 0)) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < m; i++) {
        for (auto [lx, rx, id]: have[i]) {
            if (!vis[id]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
