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
    int a, b, k, op, tp;
    string col;
} dp[148][148][22][2][2];

bool vis[148][148][22][2][2];

inline void Zlin() {
    int a, b, k, op;
    cin >> a >> b >> k >> op;
    if (a > 147 || b > 147 || (!vis[a][b][k][op][0] && !vis[a][b][k][op][1])) cout << "NA" << endl;
    else {
        string ans;
        if (vis[a][b][k][op][0]) {
            int tp = 0;
            while (a != 0 || b != 0 || k != 21 || op != 0 || tp != 0) {
                const auto pre = dp[a][b][k][op][tp];
                string tmp = pre.col;
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                a = pre.a, b = pre.b, k = pre.k, op = pre.op, tp = pre.tp;
            }
        } else {
            int tp = 1;
            while (a != 0 || b != 0 || k != 21 || op != 0 || tp != 0) {
                const auto pre = dp[a][b][k][op][tp];
                ans += pre.col;
                a = pre.a, b = pre.b, k = pre.k, op = pre.op, tp = pre.tp;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

inline void dfs(int a, int b, int k, int op, int tp) {
    if (vis[a][b][k][op][tp]) return;
    vis[a][b][k][op][tp] = true;
    if (!k) return;
    int a1, b1, k1, op1, tp1;
    if (k <= 6) {
        // 彩球打丢
        a1 = a, b1 = b, k1 = k, op1 = op ^ 1, tp1 = 0;
        if (!vis[a1][b1][k1][op1][tp1]) {
            dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, "/"};
            dfs(a1, b1, k1, op1, tp1);
        }
        // 彩球打进
        if (op == 0) {
            int i = 8 - k;
            a1 = a + i, b1 = b, k1 = k - 1, op1 = op, tp1 = tp;
            if (!vis[a1][b1][k1][op1][tp1]) {
                dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, to_string(i)};
                dfs(a1, b1, k1, op1, tp1);
            }
        } else {
            int i = 8 - k;
            a1 = a, b1 = b + i, k1 = k - 1, op1 = op, tp1 = tp;
            if (!vis[a1][b1][k1][op1][tp1]) {
                dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, to_string(i)};
                dfs(a1, b1, k1, op1, tp1);
            }
        }
    } else {
        if (tp == 0) {
            // 红球打进
            if (op == 0) {
                // 红彩连进
                for (int i = 2; i <= 7; i++) {
                    a1 = a + 1 + i, b1 = b, k1 = k - 1, op1 = op, tp1 = 0;
                    if (!vis[a1][b1][k1][op1][tp1]) {
                        dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, ("1" + to_string(i))};
                        dfs(a1, b1, k1, op1, tp1);
                    }
                }
                a1 = a + 1, b1 = b, k1 = k - 1, op1 = op, tp1 = 1;
                if (!vis[a1][b1][k1][op1][tp1]) {
                    dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, "1"};
                    dfs(a1, b1, k1, op1, tp1);
                }
            } else {
                for (int i = 2; i <= 7; i++) {
                    a1 = a, b1 = b + 1 + i, k1 = k - 1, op1 = op, tp1 = 0;
                    if (!vis[a1][b1][k1][op1][tp1]) {
                        dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, ("1" + to_string(i))};
                        dfs(a1, b1, k1, op1, tp1);
                    }
                }
                a1 = a, b1 = b + 1, k1 = k - 1, op1 = op, tp1 = 1;
                if (!vis[a1][b1][k1][op1][tp1]) {
                    dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, "1"};
                    dfs(a1, b1, k1, op1, tp1);
                }
            }
            // 红球打丢
            a1 = a, b1 = b, k1 = k, op1 = op ^ 1, tp1 = 0;
            if (!vis[a1][b1][k1][op1][tp1]) {
                dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, "/"};
                dfs(a1, b1, k1, op1, tp1);
            }
        } else {
            // 彩球打丢
            a1 = a, b1 = b, k1 = k, op1 = op ^ 1, tp1 = 0;
            if (!vis[a1][b1][k1][op1][tp1]) {
                dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, "/"};
                dfs(a1, b1, k1, op1, tp1);
            }
            // 彩球打进
            for (int i = 2; i <= 7; i++) {
                if (op == 0) a1 = a + i, b1 = b, k1 = k, op1 = op, tp1 = 0;
                else a1 = a, b1 = b + i, k1 = k, op1 = op, tp1 = 0;
                if (!vis[a1][b1][k1][op1][tp1]) {
                    string c = to_string(i);
                    dp[a1][b1][k1][op1][tp1] = {a, b, k, op, tp, c};
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
