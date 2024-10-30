//
// Created by Zlin on 2024/10/30.
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

const int N = 1010;
const int inf = 1e9;
int n, m, a[N][N], t[N][N];

bool check(int x, int y) {
    return !(x >= n || x < 0 || y >= m || y < 0);
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            t[i][j] = inf;
        }
    queue<pii> q;
    q.push({0, 0});
    t[0][0] = 0;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        int x = (u.first + 1) % n, y = u.second + 1;
        if (check(x, y) && a[x][y] == 0 && t[x][y] > t[u.first][u.second] + 1) {
            t[x][y] = t[u.first][u.second] + 1;
            q.push({x, y});
        }
        x = (u.first + 2) % n, y = u.second;
        if (check(x, y) && a[x][y] == 0 && a[(x - 1 + n) % n][y] == 0 && t[x][y] > t[u.first][u.second] + 1) {
            t[x][y] = t[u.first][u.second] + 1;
            q.push({x, y});
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++)
//            cout << t[i][j] << ' ';
//        cout << '\n';
//    }
    int ans = inf;
    for (int i = 0, x, xx; i < n; i++) {
        if (t[i][m - 1] == inf) continue;
        x = i, xx = (n - 1 + t[i][m - 1]) % n;
        ans = min({ans, t[i][m - 1] + abs(x - xx), t[i][m - 1] + n - abs(x - xx)});
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}