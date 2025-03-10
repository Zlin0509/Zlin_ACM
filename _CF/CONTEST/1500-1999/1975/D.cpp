//
// Created by Zlin on 2024/8/31.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int N = 2e5 + 5;
int n = 1, x, y, mx, mm;
int dep[N], fa[N];
vector<vector<int>> e(N);

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
    mx = max(dep[u], mx);
    for (auto v: e[u]) {
        if (v == f)continue;
        dfs(v, u);
    }
}

vi find(int a, int b) {
    vi t, o;
    if (dep[a] < dep[b])swap(a, b);
    while (dep[a] > dep[b]) {
        t.push_back(a);
        a = fa[a];
    }
    if (a == b) {
        t.push_back(b);
        return t;
    }
    while (a != b) {
        t.push_back(a), o.push_back(b);
        a = fa[a], b = fa[b];
    }
    t.push_back(a);
    reverse(o.begin(), o.end());
    for (auto it: o)t.push_back(it);
    return t;
}

inline void Zlin() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    mx = dep[0] = -1;
    if (x == y) {
        dfs(x, 0);
        cout << (n - 1) * 2 - mx << '\n';
        return;
    }
    dfs(1, 0);
    vi t = find(x, y);
    if (t[0] != x)reverse(t.begin(), t.end());
    mm = t.size();
    mx = -1;
    dfs(t[(mm - 1) / 2], 0);
    cout << (n - 1) * 2 - mx + (mm - 1) - (mm - 1) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}