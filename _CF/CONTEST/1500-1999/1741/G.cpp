//
// Created by Zlin on 2025/5/1.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 10010;

int n, m, f, k, dep[N], vis[N], h[N], p[6], idx[N];
vi e[N], have[N], val[N];

inline void bfs() {
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (int i = 0; i < k; i++) {
            if (h[p[i]] == u) {
                for (int &va: val[u]) {
                    va |= 1 << i;
                }
            }
        }
        sort(val[u].begin(), val[u].end());
        val[u].erase(unique(val[u].begin(), val[u].end()), val[u].end());

        for (int v: e[u]) {
            if (dep[v] < dep[u] + 1) continue;
            for (int va: val[u]) {
                val[v].push_back(va);
            }
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}

bool fin[N][1 << 7];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        have[i].clear();
        e[i].clear();
        val[i].clear();
        val[i].push_back(0);
        dep[i] = N << 2;
        vis[i] = 0;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> f;
    for (int i = 1; i <= f; i++) {
        cin >> h[i];
        have[h[i]].push_back(i);
        idx[i] = 0;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        idx[p[i]] = i + 1;
    }
    bfs();
    for (int i = 1; i <= f; i++) {
        for (int j = 0; j < 1 << k; j++) {
            fin[i][j] = false;
        }
    }
    fin[0][0] = true;
    for (int i = 1; i <= f; i++) {
        if (idx[i]) {
            for (int l = 0; l < 1 << k; l++) {
                fin[i][l] = fin[i - 1][l];
            }
        } else {
            for (int l = 0; l < 1 << k; l++) {
                if (fin[i - 1][l]) {
                    for (int r: val[h[i]]) {
                        fin[i][l | r] = fin[i - 1][l];
                    }
                }
            }
        }
    }
    int ans = k;
    for (int i = 0; i < 1 << k; i++) {
        if (fin[f][i]) {
            ans = min(ans, k - __builtin_popcount(i));
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
