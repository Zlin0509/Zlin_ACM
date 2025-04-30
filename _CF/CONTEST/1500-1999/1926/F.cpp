//
// Created by 27682 on 2025/4/8.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int dx[4] = {-1, -1, 1, 1}, dy[4] = {1, -1, 1, -1};
constexpr int fx[8] = {3, 3, 3, 4, 4, 5, 5, 5}, fy[8] = {3, 4, 5, 3, 5, 3, 4, 5};

char a[10][10];

bool check(int x, int y) {
    return x >= 1 && x <= 7 && y >= 1 && y <= 7;
}

bool dfs(int dep) {
    if (!dep) {
        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) {
                if (a[i][j] != 'B') continue;
                bool tag = true;
                for (int k = 0; k < 4 && tag; k++) {
                    if (check(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] != 'B') {
                        tag = false;
                    }
                }
                if (tag) return false;
            }
        }
        return true;
    }
    for (int i = 0; i < 8; i++) {
        if (a[fx[i]][fy[i]] != 'B') continue;
        a[fx[i]][fy[i]] = 'W';
        if (dfs(dep - 1)) return true;
        a[fx[i]][fy[i]] = 'B';
    }
    return false;
}

inline void Zlin() {
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= 8; i++) {
        if (dfs(i)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
