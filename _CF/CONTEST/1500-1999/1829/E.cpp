#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 5;

int n, m, f[N], siz[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
    siz[fy] += siz[fx];
}

constexpr int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> siz[i * m + j], f[i * m + j] = i * m + j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!siz[i * m + j]) continue;
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m || !siz[ii * m + jj]) continue;
                merge(i * m + j, ii * m + jj);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans = max(ans, siz[i * m + j]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
