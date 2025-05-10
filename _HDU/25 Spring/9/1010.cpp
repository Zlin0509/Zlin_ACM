//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 1e5 + 10;

int n, m, vis[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: e[u]) {
            if (vis[v] || v < u) continue;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
