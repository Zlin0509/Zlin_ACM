//
// Created by Zlin on 2025/10/28.
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

// a, b, k还剩几颗球, op谁在打球, tp当前该打什么球;

struct Node {
    int a, b, op, k, tp;
    char col;
} dp[148][148][22][2][2];

int vis[148][148][22][2][2];

inline void Zlin() {
}

inline void dfs(int a, int b, int k, int op, int tp) {
    if (vis[a][b][k][op][tp]) return;
    vis[a][b][k][op][tp] = 1;
    int a1, b1, k1, op1, tp1;
    if (k < 6) {
    } else {
        if (tp == 0) {
        } else {
            a1 = a, b1 = b, k1 = k, op1 = op ^ 1, tp1 = 0;
            if (!vis[a1][b1][k1][op1][tp1]) {
                dp[a1][b1][k1][op1][tp1] = {a, b, k, op1, tp1, '/'};
                dfs(a1, b1, k1, op1, tp1);
            }
            for (int i = 2; i <= 6; i++) {
                if (op == 0) {
                    a1 = a + i;
                    b1 = b;
                    k1 = k;
                    op1 = op;
                    tp1 = 0;
                } else {
                    a1 = a;
                    b1 = b + i;
                    k1 = k;
                    op1 = op;
                    tp1 = 0;
                }
                if (!vis[a1][b1][k1][op1][tp1]) {
                    dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, char('0' + i)};
                    dfs(a1, b1, k1, op1, tp1);
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    dfs(0, 0, 21, 0, 0);
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
