//
// Created by 27682 on 2025/4/14.
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

constexpr int N = 2000;
int n, m, w[N], cnt[N], ans[N], vis[N], dis[N];


vector<pii> e[N];

inline void dfs(int u, int val, int dep) {
    if (dep > dis[u]) return;
    ans[u] = min(ans[u], val);
    for (auto [v, co]: e[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        ++cnt[co];
        dfs(v, val + cnt[co] * w[co], dep + 1);
        vis[v] = 0;
        --cnt[co];
    }
}

inline void init() {
    for (int i = 1; i <= n; i++) ans[i] = dis[i] = 0x3f3f3f3f;
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, val]: e[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1, u, v, co; i <= m; i++) {
        cin >> u >> v >> co;
        e[u].push_back({v, co});
        e[v].push_back({u, co});
    }
    init();
    vis[1] = 1;
    dfs(1, 0, 0);
    for (int i = 2; i <= n; i++)
        cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
