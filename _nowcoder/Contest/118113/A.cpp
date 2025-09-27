//
// Created by 27682 on 2025/9/27.
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

constexpr int dx[4]{0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

inline void Zlin() {
    map<pii, int> vis, vis1;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (const auto &c: s) {
        if (c == 'U') {
            y++;
        } else if (c == 'D') {
            y--;
        } else if (c == 'L') {
            x--;
        } else {
            x++;
        }
        vis[{x, y}]++;
        vis1[{x, y}]++;
    }
    int tag = 2;
    for (int i = 0, xx = 0, yy = 0, px, py; i < n; i++) {
        char c = s[i];
        if (c == 'U') {
            yy++;
            px = 0, py = 1;
        } else if (c == 'D') {
            yy--;
            px = 0, py = -1;
        } else if (c == 'L') {
            xx--;
            px = -1, py = 0;
        } else {
            xx++;
            px = 1, py = 0;
        }
        --vis1[{xx, yy}];
        for (int k = 0, tx, ty; k < 4; k++) {
            tx = px + dx[k], ty = py + dy[k];
            if (!vis1[{x + tx, y + ty}] && xx + tx != x && yy + ty != y) tag = 1;
        }
        if (xx == x && yy == y) break;
    }
    while (q--) {
        int xx, yy;
        cin >> xx >> yy;
        if (!vis[{xx, yy}]) cout << 0 << endl;
        else {
            if (xx != x || yy != y) cout << 1 << endl;
            else cout << tag << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
