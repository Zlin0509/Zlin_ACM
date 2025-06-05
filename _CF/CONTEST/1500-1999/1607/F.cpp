//
// Created by 27682 on 2025/5/22.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;

constexpr int N = 4e6 + 5;

char c;
int n, m, tmp;
int nxt[N], val[N];
int vis[N]{2};

inline int dfs(int u) {
    if (vis[u] == 2) return val[u];
    if (vis[u] == 1) {
        int siz = 1;
        for (int it = nxt[u]; it != u; it = nxt[it]) ++siz;
        for (int it = nxt[u]; it != u; it = nxt[it]) val[it] = siz, vis[it] = 2;
        val[u] = siz, vis[u] = 2;
        return 0;
    }
    vis[u] = 1;
    dfs(nxt[u]);
    if (vis[u] != 2) {
        val[u] = val[nxt[u]] + 1;
        vis[u] = 2;
    }
    return val[u];
}

int be = 0, en = 0;

inline void Zlin() {
    cin >> n >> m;
    be = en + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ++en;
            cin >> c;
            if (c == 'L' && j != 1) nxt[en] = en - 1;
            if (c == 'R' && j != m) nxt[en] = en + 1;
            if (c == 'D' && i != n) nxt[en] = en + m;
            if (c == 'U' && i != 1) nxt[en] = en - m;
        }
    }
    int ans = 0, pos = 0;
    for (int i = be; i <= en; i++) {
        if (ans < dfs(i)) {
            ans = val[i];
            pos = i;
        }
    }
    cout << (pos - be) / m + 1 << ' ' << (pos - be) % m + 1 << ' ' << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
