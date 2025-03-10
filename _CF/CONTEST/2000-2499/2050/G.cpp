//
// Created by 27682 on 2025/2/24.
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

int n, ans;
vector<vi> e;
vi d;

int dfs(int u, int fa) {
    int max1 = -2, max2 = -2;
    for (int v: e[u]) {
        if (v == fa)
            continue;
        int now = dfs(v, u);
        if (now > max1)
            max2 = max1, max1 = now;
        else if (now > max2)
            max2 = now;
    }
    ans = max({ans, d[u], d[u] + max1, d[u] + max1 + max2});
    return max({d[u], d[u] + max1});
}

inline void Zlin() {
    cin >> n;
    e.assign(n + 1, vi());
    d.assign(n + 1, -2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++d[u], ++d[v];
    }
    ans = -2;
    dfs(1, 0);
    cout << ans + 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}