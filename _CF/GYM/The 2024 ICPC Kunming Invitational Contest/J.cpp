//
// Created by Zlin on 2024/10/5.
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

const int N = 5e5 + 10;

struct edge {
    int v, val, c;
};

inline void Zlin() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> all[n + 1];
    for (int i = 1, u, v, val, c; i <= m; i++) {
        cin >> u >> v >> c >> val;
        all[u].push_back({v, val, c});
        all[v].push_back({u, val, c});
    }
    priority_queue<pii> to[m + 1], q;
    for (auto it: all[1]) to[it.c].push({-it.val, it.v});
    vi vis(n + 1);
    vis[1] = 1;
    int a, b;
    while (k--) {
        cin >> a >> b;
        while (!to[a].empty() && -to[a].top().first <= b) {
            q.push(to[a].top());
            to[a].pop();
        }
        while (!q.empty()) {
            int v = q.top().second, d = -q.top().first;
            q.pop();
            if (vis[v]) continue;
            vis[v] = 1;
            for (auto it: all[v]) {
                if (vis[it.v]) continue;
                if (it.c == a && d + it.val <= b) q.push({-d - it.val, it.v});
                else to[it.c].push({-it.val, it.v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << vis[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}