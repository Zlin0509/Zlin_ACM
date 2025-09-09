//
// Created by 27682 on 2025/9/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;

int n, m, ans[N], dis1[N], dis2[N], d1[N], d2[N], pre[N];
vi e1[N], e2[N];

inline bool check() {
    for (int i = 1; i <= n; i++) {
        dis1[i] = 0;
        d1[i] = e2[i].size();
    }
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e1[u]) {
            if (dis1[v] && dis1[v] != dis1[u] + ans[u]) return false;
            dis1[v] = dis1[u] + ans[u];
            if (!--d1[v]) q.emplace(v);
        }
    }
    return true;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis1[i] = ans[i] = pre[i] = 0;
        dis2[i] = 1e9;
        d1[i] = d2[i] = 0;
        e1[i].clear();
        e2[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e1[u].emplace_back(v);
        ++d1[v];
        e2[v].emplace_back(u);
        ++d2[u];
    }
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e1[u]) {
            if (dis1[v] < dis1[u] + 1) {
                dis1[v] = dis1[u] + 1;
                pre[v] = u;
            }
            if (!--d1[v]) q.emplace(v);
        }
    }
    int node = n;
    while (node) {
        ans[node] = 1;
        dis2[node] = dis1[node];
        node = pre[node];
    }
    q.emplace(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e2[u]) {
            dis2[v] = min(dis2[v], dis2[u] - 1);
            if (!--d2[v]) q.emplace(v);
        }
    }
    for (int i = 1; i <= n; i++) d2[i] = e1[i].size();
    q.emplace(n);
    while (!q.empty()) {
        int u = q.front(), mx = n;
        q.pop();
        for (int v: e2[u]) mx = min(mx, dis2[v]);
        if (!ans[u]) ans[u] = dis2[u] - mx;
        for (int v: e2[u]) {
            dis2[v] = min(dis2[v], mx);
            if (!--d2[v]) q.emplace(v);
        }
    }
    if (check()) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << endl;
    } else cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
