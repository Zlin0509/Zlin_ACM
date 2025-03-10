
//
// Created by Zlin on 2024/11/1.
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

struct edge {
    int v, t;
};
vector<edge> e[N];
queue<int> T[N];

int n, t, k, a[N], ans[N], vis[N];

inline void Zlin() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) ans[i] = 0x3f3f3f3f;
    for (int i = 1, m; i <= t; i++) {
        cin >> m;
        for (int j = 1, x, y; j <= m; j++) {
            cin >> x >> y;
            e[x].push_back({y, i});
            e[y].push_back({x, i});
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        T[a[i]].push(i);
    }
    priority_queue<pii> q;
    q.push({0, 1});
    ans[1] = 0;
    for (int i = 1; i <= k; i++) {
        while (!q.empty() && -q.top().first < i) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto it: e[u]) {
                if (T[it.t].empty()) continue;
                int v = it.v, tt = T[it.t].front();
                if (ans[v] > tt) {
                    ans[v] = tt;
                    if (!vis[v])
                        q.push({-ans[v], v});
                }
            }
        }
        T[a[i]].pop();
    }
    cout << (ans[n] == 0x3f3f3f3f ? -1 : ans[n]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}