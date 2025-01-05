//
// Created by Zlin on 2024/9/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
ll ans;
const int N = 2e5 + 5;
ll dfn[N], low[N], tot, siz[N];
vi h[N], e;

inline void add(int x, int y) {
    e.push_back(y);
    h[x].push_back(e.size() - 1);
}

inline void tarjan(int x, int in_edg) {
    dfn[x] = low[x] = ++tot;
    for (int i = 0; i < h[x].size(); i++) {
        int j = h[x][i], y = e[j];
        if (!dfn[y]) {
            tarjan(y, j);
            siz[x] += siz[y];
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                ans = min(ans, (siz[y] * (siz[y] - 1) + (n - siz[y]) * (n - siz[y] - 1)) / 2);
        } else if (j != (in_edg ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
}

inline void Zlin() {
    cin >> n >> m;
    ans = 1ll * n * (n - 1) / 2;
    e.clear();
    for (int i = 1; i <= n; i++) {
        siz[i] = 1;
        dfn[i] = low[i] = 0;
        h[i].clear();
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    tarjan(1, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}