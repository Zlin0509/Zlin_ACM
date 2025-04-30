//
// Created by Zlin on 2024/10/29.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
const int inf = 1e9;

struct edge {
    int v, val, nxt;
} e[N << 1];
int head[N], tot;

inline void add(int u, int v, int c) {
    e[++tot] = {v, c, head[u]};
    head[u] = tot;
}

int n, m, Start, End, dep[N], vis[N], c[N];

inline void init() {
    tot = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = head[i] = 0;
        dep[i] = inf;
    }
}

inline void Zlin() {
    cin >> n >> m;
    init();
    for (int i = 1, u, v, val; i <= m; i++) {
        cin >> u >> v >> val;
        add(u, v, val);
        add(v, u, val);
        c[val] = inf;
    }
    cin >> Start >> End;
    dep[Start] = 0;
    priority_queue<pii> q;
    q.push({0, Start});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt) {
            c[e[i].val] = min(dep[u] + 1, c[e[i].val]);
            if (dep[e[i].v] > c[e[i].val]) {
                dep[e[i].v] = c[e[i].val];
                if (!vis[e[i].v]) q.push({-dep[e[i].v], e[i].v});
            }
        }
    }
    cout << dep[End] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}