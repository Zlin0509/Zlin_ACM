//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

constexpr int N = 2e5 + 10;
constexpr ll mo = 1e9 + 7;

int n, tag, len[N];
vi e[N];

inline void dfs(int u, int fa) {
    len[u] = 1;
    bool check = false;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        len[u] = max(len[u], len[v] + 1);
        check = true;
    }
    tag += !check;
}

inline void dfs1(int u, int fa, ll &ans) {
    ans = ans * 2 % mo;
    int cnt = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        ++cnt;
    }
    if (cnt == 1) {
        for (int v: e[u]) {
            if (v == fa) continue;
            dfs1(v, u, ans);
        }
        return;
    }
    int lx = 0, rx = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        if (!lx) lx = len[v];
        else rx = len[v];
    }
    int dif = abs(rx - lx);
    if (dif) {
        ll tmp = 1;
        for (int i = 1; i < dif; i++) tmp = tmp * 2 % mo;
        ans = ans * tmp % mo * 3 % mo;
    } else ans = ans * 2 % mo;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    tag = 0;
    dfs(1, 0);
    if (tag > 2) {
        cout << 0 << endl;
        return;
    }
    if (tag == 1) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * 2 % mo;
        cout << ans << endl;
        return;
    }
    ll ans = 1;
    dfs1(1, 0, ans);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
