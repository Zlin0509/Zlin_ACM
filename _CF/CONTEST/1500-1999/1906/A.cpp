//
// Created by 27682 on 2025/2/26.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s[3];
string ans = "CCC";
int vis[3][3];

int dx[8]{0, -1, -1, -1, 0, 1, 1, 1}, dy[8]{1, 1, 0, -1, -1, -1, 0, 1};

bool check(int x, int y) {
    return x >= 0 && x <= 2 && y >= 0 && y <= 2 && !vis[x][y];
}

inline void dfs(int x, int y, string now) {
    if (now.size() == 3) {
        ans = min(ans, now);
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!check(xx, yy))
            continue;
        dfs(xx, yy, now + s[xx][yy]);
    }
    vis[x][y] = 0;
}

inline void Zlin() {
    for (int i = 0; i < 3; i++)
        cin >> s[i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            dfs(i, j, "");
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}