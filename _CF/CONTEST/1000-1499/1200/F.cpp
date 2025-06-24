//
// Created by 27682 on 2025/6/23.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 1005;
constexpr int all = 2520;

// all = 2520

int n, k[N], m[N], q;
vi e[N];

int ans[N][all];
int instk[N][all], stk[N * all], dep[N][all];
int vis[N];

inline int dfs(int x, int y) {
    instk[x][y] = 1;
    if (ans[x][y]) return ans[x][y];
    stk[dep[x][y]] = x;
    int xx = e[x][y % m[x]], yy = (y + k[xx]) % all;
    if (instk[xx][yy]) {
        if (ans[xx][yy]) return ans[x][y] = ans[xx][yy];
        int l = dep[xx][yy], r = dep[x][y];
        for (int i = l; i <= r; i++) vis[stk[i]] = 0;
        for (int i = l; i <= r; i++) if (!vis[stk[i]]) ans[x][y] += ++vis[stk[i]];
        return ans[x][y];
    }
    dep[xx][yy] = dep[x][y] + 1;
    return ans[x][y] = dfs(xx, yy);
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        k[i] = (k[i] % all + all) % all;
    }
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        e[i].assign(m[i], 0);
        for (int &it: e[i]) cin >> it;
    }
    cin >> q;
    while (q--) {
        int x, c;
        cin >> x >> c;
        c = (c % all + all) % all;
        cout << dfs(x, (c + k[x]) % all) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
