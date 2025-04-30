//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 5;

int n, m;
int f[N], siz[N], a[N];
vi e[N], val[N];
priority_queue<pii, vector<pii>, greater<pii> > group[N];

inline int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fy] = fx;
    siz[fx] += siz[fy];
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        f[i] = i, siz[i] = 1;
        e[i].clear();
        val[i].clear();
        while (!group[i].empty()) group[i].pop();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[a[i]].push_back(i);
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 1) {
        cout << (a[1] == 0 ? "YES" : "NO") << endl;
        return;
    }
    for (int s: val[0]) {
        if (s != find(s)) continue;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: e[u]) {
                if (find(u) == find(v)) continue;
                if (siz[f[u]] >= a[v]) {
                    while (!group[f[v]].empty()) {
                        pii p = group[f[v]].top();
                        group[f[v]].pop();
                        if (siz[f[v]] + siz[f[u]] < p.first) group[s].push(p);
                        else if (find(u) != find(p.second)) {
                            merge(u, p.second);
                            q.push(p.second);
                        }
                    }
                    if (find(u) != find(v)) {
                        merge(u, v);
                        q.push(v);
                    }
                } else group[f[u]].push({a[v], v});
            }
            while (!group[f[u]].empty() && group[f[u]].top().first <= siz[f[u]]) {
                int v = group[s].top().second;
                group[f[u]].pop();
                if (find(u) != find(v)) {
                    merge(u, v);
                    q.push(v);
                }
            }
        }
    }
    cout << (siz[find(1)] == n ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
