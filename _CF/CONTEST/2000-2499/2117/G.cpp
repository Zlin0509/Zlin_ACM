//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

constexpr int N = 2e5 + 10;
constexpr ll mo = 1e9 + 7;

int n, m, f[N], val[N];

struct edge {
    int val, u, v;

    bool operator<(const edge &other) const {
        return val < other.val;
    }
};

vector<edge> e;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int u, int v) {
    int fx = find(u), fy = find(v);
    if (fx == fy) return;
    f[fx] = fy;
    val[fy] = min(val[fy], val[fx]);
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        val[i] = 2e9;
        f[i] = i;
    }
    e.clear();
    for (int i = 1; i <= m; i++) {
        edge tmp;
        cin >> tmp.u >> tmp.v >> tmp.val;
        e.push_back(tmp);
    }
    sort(e.begin(), e.end());
    int ans = 2e9;
    for (auto [valx, u, v]: e) {
        val[find(u)] = min(val[find(u)], valx);
        val[find(v)] = min(val[find(v)], valx);
        merge(u, v);
        if (find(1) == find(n)) ans = min(valx + val[find(1)], ans);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
