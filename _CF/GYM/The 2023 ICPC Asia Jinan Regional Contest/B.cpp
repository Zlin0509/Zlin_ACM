//
// Created by Zlin on 2024/10/11.
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

const int N = 1e5 + 10, NN = 1010;
const int mo = 998244353;

int n, k;
vi e[N];

int dp[N][NN], cur[NN];
int siz[N];

inline void dfs_1(int u, int fa) {
    for (int i = 0; i <= k + 1; i++) dp[u][i] = 0;
    siz[u] = dp[u][1] = 1;
    for (auto v: e[u]) {
        if (v == fa) continue;
        dfs_1(v, u);
        for (int i = 0; i <= min(siz[u] + siz[v], k + 1); i++) cur[i] = 0;
        for (int i = 0; i <= min(siz[u], k + 1); i++) {
            for (int j = 0; j <= min(siz[v], k + 1); j++) {
                if (i + j <= k + 1 && dp[u][i] && dp[v][j]) {
                    int s = 1ll * dp[u][i] * dp[v][j] % mo;
                    cur[i + j] = (cur[i + j] + s) % mo;
                }
            }
        }
        for (int i = 1; i <= min(siz[u] + siz[v], k + 1); i++) dp[u][i] = cur[i];
        siz[u] += siz[v];
    }
    dp[u][0] = (dp[u][k] + dp[u][k + 1]) % mo;
}

unordered_map<int, int> Dp[N];
unordered_map<int, int> Cur;

inline void dfs_2(int u, int fa) {
    Dp[u].clear();
    Dp[u][1] = 1;
    for (auto v: e[u]) {
        if (v == fa) continue;
        dfs_2(v, u);
        Cur.clear();
        for (auto i: Dp[u]) {
            for (auto j: Dp[v]) {
                if (i.first + j.first > k + 1) continue;
                int s = 1ll * i.second * j.second % mo;
                Cur[i.first + j.first] = (Cur[i.first + j.first] + s) % mo;
            }
        }
        Dp[u] = Cur;
    }
    if (Dp[u].find(k) != Dp[u].end()) Dp[u][0] = (Dp[u][0] + Dp[u][k]) % mo;
    if (Dp[u].find(k + 1) != Dp[u].end()) Dp[u][0] = (Dp[u][0] + Dp[u][k + 1]) % mo;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (k <= 1000) {
        dfs_1(1, 0);
        cout << dp[1][0] << '\n';
    } else {
        dfs_2(1, 0);
        cout << Dp[1][0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}