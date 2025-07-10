//
// Created by 27682 on 2025/7/10.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int N = 510;

int n, m;
int f[N][N][2];
vi e[N];

struct node {
    int u, v, op;
};

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    f[1][n][0] = 1;
    queue<node> q;
    q.emplace(1, n, 0);
    while (!q.empty()) {
        auto [l, r, o] = q.front();
        q.pop();
        if (o) {
            for (int rx: e[r]) {
                if (rx == l || f[l][rx][o ^ 1]) continue;
                f[l][rx][o ^ 1] = f[l][r][o] + 1;
                q.emplace(l, rx, o ^ 1);
            }
        } else {
            for (int lx: e[l]) {
                if (f[lx][r][o ^ 1]) continue;
                f[lx][r][o ^ 1] = f[l][r][o] + 1;
                q.emplace(lx, r, o ^ 1);
            }
        }
    }
    if (!f[n][1][0]) {
        cout << -1 << endl;
        return;
    }
    cout << (f[n][1][0] >> 1) << endl;
    q.emplace(n, 1, 0);
    vi res;
    res.emplace_back(1), res.emplace_back(n);
    while (!q.empty()) {
        auto [l, r, o] = q.front();
        q.pop();
        if (o) {
            for (int lx: e[l]) {
                if (lx != r && f[lx][r][o ^ 1] + 1 == f[l][r][o]) {
                    res.emplace_back(lx);
                    q.emplace(lx, r, o ^ 1);
                    break;
                }
            }
        } else {
            for (int rx: e[r]) {
                if (f[l][rx][o ^ 1] + 1 == f[l][r][o]) {
                    res.emplace_back(rx);
                    q.emplace(l, rx, o ^ 1);
                    break;
                }
            }
        }
    }
    // for (int it: res) cout << it << ' ';
    // cout << endl;
    for (int i = 0; i <= f[n][1][0] >> 1; i++) cout << res[i * 2] << ' ';
    cout << endl;
    for (int i = 0; i <= f[n][1][0] >> 1; i++) cout << res[i * 2 + 1] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
