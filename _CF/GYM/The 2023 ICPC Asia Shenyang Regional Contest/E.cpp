//
// Created by Zlin on 2024/10/12.
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

struct node {
    int x, y, c;
};

int dep[222][222][2];

inline void Zlin() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    queue<node> z;
    z.push({x, y, 0});
    dep[x][y][0] = 1;
    while (!z.empty()) {
        node u = z.front();
        z.pop();
        for (int xx = 0; xx <= u.x; xx++) {
            for (int yy = 0; yy <= u.y; yy++) {
                if (xx + yy > p || dep[x - u.x + xx][y - u.y + yy][u.c ^ 1] ||
                    (u.x - xx && u.x - xx + q < u.y - yy))
                    continue;
                dep[x - u.x + xx][y - u.y + yy][u.c ^ 1] = dep[u.x][u.y][u.c] + 1;
                z.push({x - u.x + xx, y - u.y + yy, u.c ^ 1});
            }
        }
    }
    int ans = 5000;
    for (int i = 0; i < y; i++)
        if (dep[x][i][1])
            ans = min(ans, dep[x][i][1] - 1);
    cout << (ans == 5000 ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}