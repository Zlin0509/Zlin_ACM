//
// Created by Zlin on 2024/11/2.
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

const ll mo = 998244353;
const int N = 1e5 + 5;
int n;

struct edge {
    int to, val;
};

vector<edge> e[N];
ll cnt = 0;
ll ans = 0;
ll vis[N]{}, dp[N]{}, siz1[N]{}, siz2[N]{};

void dfs(int u) {
    vis[u] = 1;
    for (auto it: e[u]) {
        int v = it.to, val = it.val;
        if (!val) dp[u] = (dp[u] + siz1[u]) % mo;
        if (!vis[v]) dfs(v);
        val ? siz1[u]++ : siz2[u]++;
        dp[u] = (dp[u] + dp[v] + siz1[u] * siz2[v] % mo) % mo;
        siz1[u] = (siz1[u] + siz1[v]) % mo, siz2[u] = (siz2[u] + siz2[v]) % mo;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1, s, v, val; i <= n; i++) {
        cin >> s;
        while (s) {
            cin >> v >> val;
            e[i].push_back({v, val});
            s--;
        }
    }
    dfs(1);
    cout << dp[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}