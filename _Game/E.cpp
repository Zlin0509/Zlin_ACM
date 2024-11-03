//
// Created by Zlin on 2024/11/3.
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

int n, m;
int a[110][110];

struct aa {
    int xa, ya, xb, yb, xc, yc;
};
vector<aa> ans;

void check(int x, int y) {
    if (a[x][y] == 0 && a[x][y + 1] == 0) return;
    if (a[x][y] == 1 && a[x][y + 1] == 1) {
        a[x][y] ^= 1, a[x][y + 1] ^= 1, a[x + 1][y] ^= 1;
        ans.push_back({x, y, x, y + 1, x + 1, y});
    } else if (a[x][y] == 1) {
        a[x][y] ^= 1, a[x + 1][y] ^= 1, a[x + 1][y + 1] ^= 1;
        ans.push_back({x, y, x + 1, y, x + 1, y + 1});
    } else {
        a[x][y + 1] ^= 1, a[x + 1][y] ^= 1, a[x + 1][y + 1] ^= 1;
        ans.push_back({x, y + 1, x + 1, y, x + 1, y + 1});
    }
}

void check1(int x, int y) {
    if (a[x][y] == 0 && a[x + 1][y] == 0) return;
    if (a[x][y] == 1 && a[x + 1][y] == 1) {
        a[x][y] ^= 1, a[x + 1][y] ^= 1, a[x + 1][y + 1] ^= 1;
        ans.push_back({x, y, x + 1, y, x + 1, y + 1});
    } else if (a[x][y] == 1) {
        a[x][y] ^= 1, a[x][y + 1] ^= 1, a[x + 1][y + 1] ^= 1;
        ans.push_back({x, y, x, y + 1, x + 1, y + 1});
    } else {
        a[x + 1][y] ^= 1, a[x][y + 1] ^= 1, a[x + 1][y + 1] ^= 1;
        ans.push_back({x + 1, y, x, y + 1, x + 1, y + 1});
    }
}

int dx[4]{0, 0, 1, 1}, dy[4]{0, 1, 0, 1};

void check2(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (a[xx][yy] == 1) ++cnt;
    }
    if (cnt == 1) {
        int tag1 = -1, tag2 = -1, tag3 = -1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (a[xx][yy] == 1) {
                tag1 = i;
            } else {
                if (tag2 == -1) tag2 = i;
                else if (tag3 == -1) tag3 = i;
            }
        }
        a[x + dx[tag1]][y + dy[tag1]] ^= 1, a[x + dx[tag2]][y + dy[tag2]] ^= 1, a[x + dx[tag3]][y + dy[tag3]] ^= 1;
        ans.push_back({x + dx[tag1], y + dy[tag1], x + dx[tag2], y + dy[tag2], x + dx[tag3], y + dy[tag3]});
        cnt = 2;
    }
    if (cnt == 2) {
        int tag1 = -1, tag2 = -1, tag3 = -1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (a[xx][yy] == 1) {
                tag1 = i;
            } else {
                if (tag2 == -1) tag2 = i;
                else if (tag3 == -1) tag3 = i;
            }
        }
        a[x + dx[tag1]][y + dy[tag1]] ^= 1, a[x + dx[tag2]][y + dy[tag2]] ^= 1, a[x + dx[tag3]][y + dy[tag3]] ^= 1;
        ans.push_back({x + dx[tag1], y + dy[tag1], x + dx[tag2], y + dy[tag2], x + dx[tag3], y + dy[tag3]});
        cnt = 3;
    }
    if (cnt == 3) {
        int tag1 = -1, tag2 = -1, tag3 = -1;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (a[xx][yy] == 1) {
                if (tag1 == -1) tag1 = i;
                else if (tag2 == -1) tag2 = i;
                else if (tag3 == -1) tag3 = i;
            }
        }
        a[x + dx[tag1]][y + dy[tag1]] ^= 1, a[x + dx[tag2]][y + dy[tag2]] ^= 1, a[x + dx[tag3]][y + dy[tag3]] ^= 1;
        ans.push_back({x + dx[tag1], y + dy[tag1], x + dx[tag2], y + dy[tag2], x + dx[tag3], y + dy[tag3]});
    }
    if (!cnt) return;
}

inline void Zlin() {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    ans.clear();
    for (int x = 1; x < n; x++)
        for (int y = 1; y < m; y++)
            check(x, y);
    for (int y = 1, x = n - 1; y < m - 1; y++)
        check1(x, y);
    check2(n - 1, m - 1);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++)
//            cout << a[i][j];
//        cout << '\n';
//    }
    cout << ans.size() << '\n';
    for (auto it: ans)
        cout << it.xa << ' ' << it.ya << ' ' << it.xb << ' ' << it.yb << ' ' << it.xc << ' ' << it.yc << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}