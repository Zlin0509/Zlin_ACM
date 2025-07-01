//
// Created by 27682 on 2025/7/1.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int N = 1e5 + 10;

vi e[N];
int n, m, in[N], ans[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        ++in[u];
        e[v].push_back(u);
    }
    priority_queue<int> pq;
    int tot = n;
    for (int i = 1; i <= n; i++) if (!in[i]) pq.push(i);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans[u] = tot--;
        for (int v: e[u]) {
            if (!--in[v]) {
                pq.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
