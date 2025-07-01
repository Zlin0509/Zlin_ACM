//
// Created by 27682 on 2025/7/1.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10;

int n, m, vis[N], fa[N];
vi e[N], g[N];
set<pii> st;
vector<tuple<int, int, int> > ans;

inline void dfs(int u) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (vis[v]) continue;
        fa[v] = u;
        g[u].push_back(v);
        dfs(v);
    }
}

inline void dfs1(int u) {
    for (int v: g[u]) dfs1(v);
    vi tmp;
    for (int v: e[u]) {
        if (v != fa[u] && st.find({min(u, v), max(u, v)}) != st.end()) {
            tmp.push_back(v);
        }
    }
    while (tmp.size() >= 2) {
        int l = tmp.back();
        tmp.pop_back();
        int r = tmp.back();
        tmp.pop_back();
        ans.push_back({l, u, r});
        st.erase({min(l, u), max(l, u)});
        st.erase({min(r, u), max(r, u)});
    }
    if (!tmp.empty() && fa[u]) {
        ans.push_back({fa[u], u, tmp[0]});
        st.erase({min(fa[u], u), max(fa[u], u)});
        st.erase({min(tmp[0], u), max(tmp[0], u)});
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        st.insert({min(a, b), max(a, b)});
    }
    vi sx;
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i), sx.push_back(i);
    for (int it: sx) dfs1(it);
    cout << ans.size() << endl;
    for (auto [x, y, z]: ans) cout << x << " " << y << " " << z << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
