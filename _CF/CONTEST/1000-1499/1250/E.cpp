//
// Created by 27682 on 2025/6/26.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;

int n, m, k, f[101], siz[101], vis[101];
string s[51];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fy] = fx;
    siz[fx] += siz[fy];
}

inline bool check1(string x, string y) {
    int res = 0;
    for (int i = 0; i < m; i++) res += x[i] == y[i];
    return res >= k;
}

inline bool check2(string x, string y) {
    int res = 0;
    for (int i = 0; i < m; i++) res += x[i] == y[m - 1 - i];
    return res >= k;
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n * 2; i++) {
        f[i] = i;
        vis[i] = 0;
        siz[i] = i > n;
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool v1 = check1(s[i], s[j]), v2 = check2(s[i], s[j]);
            if (v1 && v2) continue;
            if (v1 && !v2) {
                merge(i, j);
                merge(i + n, j + n);
            }
            if (!v1 && v2) {
                merge(i, j + n);
                merge(i + n, j);
            }
            if (!v1 && !v2) {
                cout << -1 << endl;
                return;
            }
        }
    }
    vi res;
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(i + n)) {
            cout << -1 << endl;
            return;
        }
        if (vis[find(i)]) continue;
        if (vis[find(i + n)]) {
            res.push_back(i);
        } else if (siz[find(i)] > siz[find(i + n)]) {
            res.push_back(i);
            vis[find(i + n)] = 1;
        } else vis[find(i)] = 1;
    }
    cout << res.size() << endl;
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
