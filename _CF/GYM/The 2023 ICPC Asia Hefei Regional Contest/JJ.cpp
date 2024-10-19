//
// Created by Zlin on 2024/10/19.
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

const int N = 3e5 + 5;
const ll inf = 1e17;

int n, m, vis[N];
ll dis1[N], dis2[N], ans = inf;

struct edge {
    int v, val;

    bool operator<(const edge &x) const {
        return val < x.val;
    }
};

vector<edge> e[N];

void dfs(int u, ll top1, ll top2) {
    if (top1 + top2 >= ans)return;
    if (u == n && top1 + top2 < ans) {
        ans = top1 + top2;
        return;
    }
    vis[u] = 1;
    for (edge it: e[u]) {
        int v = it.v;
        ll val = it.val;
        if (vis[v]) continue;
        if (val >= top1) dfs(v, val, top1);
        else if (val >= top2) dfs(v, top1, val);
        else dfs(v, top1, top2);
    }
    vis[u] = 0;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v, val; i <= m; i++) {
        cin >> u >> v >> val;
        e[u].push_back({v, val});
        e[v].push_back({u, val});
    }
    for (int i = 1; i <= n; i++)
        sort(e[i].begin(), e[i].end());
    dfs(1, 0, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}