//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int N = 2e5 + 10;

int n, k, val[N], mval[N], id, tag[N];
vi e[N];

inline void dfs(int u, int fa) {
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        val[u] += val[v];
        mval[u] = max(mval[u], val[v]);
    }
}

vi ans;

inline void dfs1(int u, int fa) {
    if (tag[u]) ans.push_back(u);
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs1(v, u);
    }
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1, x; i <= k * 2; i++) {
        cin >> x;
        tag[x] = val[x] = 1;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (k * 2 - val[i] <= k && mval[i] <= k) {
            id = i;
            break;
        }
    }
    dfs1(id, 0);
    cout << 1 << endl << id << endl;
    for (int i = 0; i < k; i++) cout << ans[i] << ' ' << ans[i + k] << ' ' << id << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
