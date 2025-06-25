//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


typedef vector<int> vi;

constexpr int N = 2e5 + 10;
constexpr int INF = 1e9;

int n, a[2][N], vis[N * 2];
vi idx[2][N * 2], son[N * 2];

int f[N * 2], siz[N * 2];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (fx > fy) swap(fx, fy);
    f[fy] = fx;
    siz[fx] += siz[fy];
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n * 2; i++) {
        son[i].clear();
        idx[0][i].clear(), idx[1][i].clear();
        f[i] = i;
        siz[i] = 1;
        vis[i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            idx[i][a[i][j]].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        int cl = idx[0][i].size(), cr = idx[1][i].size();
        if (cl + cr != 2) {
            cout << -1 << endl;
            return;
        }
        if (cl == 1 && cr == 1) {
            int x = idx[0][i][0], y = idx[1][i][0];
            merge(x, y), merge(x + n, y + n);
        }
        if (cl == 2) {
            int x = idx[0][i][0], y = idx[0][i][1];
            merge(x, y + n), merge(x + n, y);
        }
        if (cr == 2) {
            int x = idx[1][i][0], y = idx[1][i][1];
            merge(x, y + n), merge(x + n, y);
        }
    }
    for (int i = 1; i <= n * 2; i++) son[find(i)].push_back(i);
    int ans = 0;
    vi res;
    for (int i = 1; i <= n; i++) {
        if (vis[f[i]]) continue;
        vis[f[i]] = vis[f[i + n]] = 1;
        int all = son[f[i]].size(), tot = 0;
        for (int it: son[f[i]]) if (it <= n) ++tot;
        ans += min(tot, all - tot);
        if (tot < all - tot) {
            for (int it: son[f[i]]) {
                if (it <= n) {
                    res.push_back(it);
                }
            }
        } else {
            for (int it: son[f[i]]) {
                if (it > n) {
                    res.push_back(it - n);
                }
            }
        }
    }
    cout << ans << endl;
    for (int it: res) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
