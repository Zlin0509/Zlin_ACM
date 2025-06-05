//
// Created by Zlin on 2025/5/24.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, vis[502][502];
char c[502][502];

vi e[502][502];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 0;
            e[i][j].clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'L') e[i][j - 1].push_back(0);
            if (c[i][j] == 'R') e[i][j + 1].push_back(1);
            if (c[i][j] == 'U') e[i - 1][j].push_back(2);
            if (c[i][j] == 'D') e[i + 1][j].push_back(3);
        }
    }
    if (c[1][m] != '.') {
        cout << "No" << endl;
        return;
    }
    vis[1][m] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'C') {
                if (e[i][j].size() != 2) {
                    cout << "No" << endl;
                    return;
                }
                for (int k: e[i][j]) vis[i + dx[k]][j + dy[k]] = 1;
                vis[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
