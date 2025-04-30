//
// Created by Zlin on 2024/9/10.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
const ll inf = 1e15;
struct edge {
    int v;
    ll v1, v2;
};

struct node {
    ll val;
    int pos;

    bool operator<(const node &x) const {
        if (x.val != val) return val > x.val;
        return pos > x.pos;
    }
};

map<int, int> used;
vi have;
int n, m;
ll t, a, b;
ll vis[N], d[N];
vector<edge> e[N];

inline ll cal(edge it, int u) {
    if (d[u] >= b || d[u] + it.v1 <= a) return d[u] + it.v1;
    return min(b + it.v1, d[u] + it.v2);
}

inline void dij(int s, int l) {
    priority_queue<node> p;
    p.push({l, s});
    d[s] = l;
    int u;
    while (!p.empty()) {
        u = p.top().pos;
        p.pop();
        if (vis[u] || d[u] >= t) continue;
        vis[u] = 1;
        for (edge it: e[u]) {
            if (cal(it, u) < d[it.v]) {
                d[it.v] = cal(it, u);
                if (!vis[it.v]) p.push({d[it.v], it.v});
            }
        }
    }
}

inline bool check(int l) {
    for (int i: have)d[i] = inf, vis[i] = 0;
    dij(1, l);
    return d[n] <= t;
}

inline void init() {
    for (int i: have) e[i].clear();
    used.clear(), have.clear();
}

inline void Zlin() {
    cin >> n >> m;
    cin >> t >> a >> b;
    for (int i = 1, x, y, z, q; i <= m; i++) {
        cin >> x >> y >> z >> q;
        e[x].push_back({y, z, q});
        e[y].push_back({x, z, q});
        if (!used[x]) ++used[x], have.push_back(x);
        if (!used[y]) ++used[y], have.push_back(y);
    }
    int l = 0, r = t, mid, ans = -1;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (check(l)) ans = l;
    cout << ans << '\n';
    init();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}