//
// Created by 27682 on 2025/7/18.
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

constexpr int N = 110;

int n, m;
int a[N][N];

struct Node {
    int val;
    int x, y;

    bool operator<(const Node &b) const {
        return val < b.val;
    }
};

vector<Node> v;

vector<pii> need;

int used[N][N];

constexpr int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

inline void Zlin() {
    v.clear();
    need.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            used[i][j] = 0;
            v.emplace_back(a[i][j], i, j);
        }
    }
    while (!v.empty()) {
        auto [vx, x, y] = v.back();
        v.pop_back();
        if (used[x][y]) continue;
        need.emplace_back(x, y);
        used[x][y] = 1;
        queue<pii> q;
        q.emplace(x, y);
        while (!q.empty()) {
            x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx < 1 || xx > n || yy < 1 || yy > m || used[xx][yy]) continue;
                used[xx][yy] = 1;
                q.emplace(xx, yy);
            }
        }
    }
    need.emplace_back(1, 1);
    sort(need.begin(), need.end());
    need.erase(unique(need.begin(), need.end()), need.end());
    for (auto [x, y]: need) cout << x << ' ' << y << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
