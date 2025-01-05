//
// Created by Zlin on 2024/9/11.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
const int inf = 1e9 + 7;
int n, m;
bool ans[N];
vi e[N], vis(N), d(N);

struct node {
    int val, pos;

    bool operator<(const node &x) const {
        if (x.val != val) return val > x.val;
        return pos > x.pos;
    }
};

inline void dij(int s) {
    priority_queue<node> q;
    q.push({0, s});
    for (int i = 2; i <= n; i++) d[i] = inf;
    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().pos;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v: e[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                if (!vis[v]) q.push({d[v], v});
            }
        }
    }
}

inline void init() {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        e[i].clear();
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i < n; i++) e[i].push_back(i + 1);
    dij(1);

    int l = 0;
    for (int u = 1; u < n; u++) {
        l <= u ? ans[u] = true : ans[u] = false;
        for (int v: e[u])
            l = max(v - d[u] - 1, l);
    }

    for (int i = 1; i < n; i++)cout << ans[i];
    cout << '\n';
    init();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}