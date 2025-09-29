//
// Created by Zlin on 2025/9/29.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 5;

int n, c[N], f[N];
vi e[N];

unordered_map<int, int> mp[N];

struct Node {
    int dep, fa, son, siz, val, top;
} tn[N];

inline void dfs1(int u) {
    tn[u].fa = f[u];
    tn[u].dep = tn[tn[u].fa].dep + 1;
    if (c[u]) {
        tn[u].siz = 1;
        return;
    }
    int tmp = -1;
    for (int v: e[u]) {
        dfs1(v);
        tn[u].siz += tn[v].siz;
        if (tn[v].siz > tmp) {
            tmp = tn[v].siz;
            tn[u].son = v;
        }
    }
}

inline void dfs2(int u, int top) {
    tn[u].top = top;
    if (!tn[u].son) return;
    dfs2(tn[u].son, top);
    for (int v: e[u]) {
        if (v != tn[u].son) {
            dfs2(v, v);
        }
    }
}

inline void dfs3(int u) {
    if (c[u]) {
        int top = tn[u].top;
        if (!mp[top].contains(c[u])) {
            int mm = n + 1;
            for (const auto &it: mp[top]) mm = min(mm, it.second);
            if (mm == n + 1) mm = 0;
            mp[top][c[u]] = 1 + mm;
        }
        mp[top][0] += 1;
    }
    if (tn[u].son) dfs3(tn[u].son);
    for (int v: e[u]) if (v != tn[u].son) dfs3(v);
    if (tn[u].top == u) {
        int fa = tn[tn[u].fa].top, mm = n + 1;
        for (const auto &it: mp[u]) mm = min(mm, it.second);
        for (const auto &it: mp[u]) {
            if (it.first == 0) {
                mp[fa][it.first] += it.second;
            } else {
                if (!mp[fa].contains(it.first)) mp[fa][it.first] = mp[fa][0] + 1;
                mp[fa][it.first] += min(mm, it.second - 1);
            }
        }
    }
}

/*

11
1 2 2 4 4 6 6 8 8 10
0 0 1 0 3 0 1 0 2 0 2

 */

inline void Zlin() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
        e[f[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    dfs1(1), dfs2(1, 1);
    set<int> st, pre;
    dfs3(1);
    int ans = n;
    for (const auto &it: mp[1]) ans = min(ans, it.second);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
