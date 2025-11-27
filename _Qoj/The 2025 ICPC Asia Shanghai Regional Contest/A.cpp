//
// Created by Zlin on 2025/11/27.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 3e4 + 10;

int n, dep[N], val[N], mx, tag, fa[N], vis[N];
vi e[N];

set<pii> st;

inline void dfs(int u, int f) {
    mx = max(mx, dep[u]);
    for (int v: e[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

inline void dfs1(int u, int f) {
    val[u] = dep[u] == tag;
    for (int v: e[u]) {
        if (v == f || dep[v] > tag || vis[v]) continue;
        dfs1(v, u);
        val[u] += val[v];
    }
}

inline void dfs2(int u, int f) {
    if (val[u] <= mx) st.insert({val[u], u});
    for (int v: e[u]) {
        if (v == f || dep[v] > tag || vis[v]) continue;
        dfs2(v, u);
    }
}

inline void remove(int u, int f) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (v == f || dep[v] > tag || vis[v]) continue;
        remove(v, u);
    }
}

inline void out(int u, int f) {
    if (dep[u] == tag) {
        cout << "! " << u << endl;
        return;
    }
    for (int v: e[u]) {
        if (v == f || dep[v] > tag || vis[v]) continue;
        out(v, u);
    }
}

inline void Zlin() {
    cin >> n;
    mx = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = fa[i] = 0;
        e[i].clear();
    }
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        e[i].emplace_back(fa[i]);
        e[fa[i]].emplace_back(i);
    }
    int s = 1, f = fa[s];
    dfs(s, 0);
    int l = 0, r = mx, mid, res;
    while (l < r) {
        mid = l + r >> 1;
        cout << "? " << s << " " << mid << endl;
        cin >> res;
        if (res) r = mid;
        else l = mid + 1;
    }
    tag = l;
    while (dep[s] != tag) {
        dfs1(s, f);
        mx = val[s] / 2;
        if (val[s] == 1) {
            out(s, f);
            return;
        }
        st.clear();
        dfs2(s, f);
        int sx = prev(st.end())->second, dif = tag - dep[sx];
        cout << "? " << sx << " " << dif << endl;
        cin >> res;
        if (res) s = sx, f = fa[s];
        else remove(sx, fa[sx]);
    }
    cout << "! " << s << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
