//
// Created by 27682 on 2025/7/16.
//

#include "bits/stdc++.h"
// #define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 51;
constexpr int inf = 1e9;
constexpr int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int ans = inf;
int n, m, k, vis[N][N];
pii s, t;
char a[N][N];

struct node {
    string s;
    int val, x, y;

    bool operator<(const node &b) const {
        if (s.size() != b.s.size()) return s.size() > b.s.size();
        return s > b.s;
    }
};

set<int> have[N][N];

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') s = {i, j};
            if (a[i][j] == 'T') t = {i, j};
        }
    }
    priority_queue<node> pq;
    pq.emplace("", 0, s.first, s.second);
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        for (int kk = 0; kk < 4; kk++) {
            int xx = u.x + dx[kk], yy = u.y + dy[kk];
            if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == 'S') continue;
            if (pii(xx, yy) == t) {
                cout << u.s << endl;
                return;
            }
            int vv = u.val | 1 << (a[xx][yy] - 'a');
            if (__builtin_popcount(vv) > k || have[xx][yy].contains(vv)) continue;
            if (vis[xx][yy] && vis[xx][yy] == (vis[xx][yy] & vv)) continue;
            vis[xx][yy] = vv;
            have[xx][yy].insert(vv);
            pq.emplace(u.s + a[xx][yy], vv, xx, yy);
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
