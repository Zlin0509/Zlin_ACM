//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 2e5 + 10;

int s, t, ds, dt;
int n, m, f[N], tot;
vi e[N];

struct edge {
    int u, v;
} lines[N * 2];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    --tot;
    f[fx] = fy;
}

int vis[N], op[N];

vector<pii> ans;

inline void dfs(int u) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (vis[v]) continue;
        merge(u, v);
        ans.emplace_back(u, v);
        dfs(v);
    }
}

vi a, b, ca, cb;

inline void Zlin() {
    cin >> n >> m;
    tot = n;
    for (int i = 1; i <= n; i++) {
        op[i] = 0;
        f[i] = i;
        e[i].clear();
    }
    for (int i = 1; i <= m; i++) cin >> lines[i].u >> lines[i].v;
    cin >> s >> t >> ds >> dt;
    bool tag = false;
    for (int i = 1; i <= m; i++) {
        if ((lines[i].u == s || lines[i].u == t) && (lines[i].v == s || lines[i].v == t)) {
            tag = true;
            continue;
        }
        if (lines[i].u == s || lines[i].u == t) {
            e[lines[i].u].emplace_back(lines[i].v);
        } else if (lines[i].v == s || lines[i].v == t) {
            e[lines[i].v].emplace_back(lines[i].u);
        } else {
            e[lines[i].u].emplace_back(lines[i].v);
            e[lines[i].v].emplace_back(lines[i].u);
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i] && i != s && i != t) dfs(i);
    for (int i: e[s]) op[find(i)] |= 1;
    for (int i: e[t]) op[find(i)] |= 2;
    for (int i: e[s]) {
        if (op[find(i)] == 3) {
            ca.emplace_back(i);
        } else {
            a.emplace_back(i);
        }
    }
    for (int i: e[t]) {
        if (op[find(i)] == 3) {
            cb.emplace_back(i);
        } else {
            b.emplace_back(i);
        }
    }
    while (!a.empty() && ds) {
        if (find(s) != find(a.back())) {
            merge(s, a.back());
            ans.emplace_back(s, a.back());
            --ds;
        }
        a.pop_back();
    }
    while (!b.empty() && dt) {
        if (find(t) != find(b.back())) {
            merge(t, b.back());
            ans.emplace_back(t, b.back());
            --dt;
        }
        b.pop_back();
    }
    if (ca.empty()) {
        if (!tag || !ds || !dt) {
            cout << "No" << endl;
            return;
        }
        --ds, --dt;
        merge(s, t);
        ans.emplace_back(s, t);
    } else {
        sort(ca.begin(), ca.end(), [&](int x, int y) {
            return find(x) < find(y);
        });
        sort(cb.begin(), cb.end(), [&](int x, int y) {
            return find(x) < find(y);
        });
        while (!ca.empty() && !cb.empty() && ds + dt) {
            if (ds && find(s) != find(ca.back())) {
                merge(s, ca.back());
                ans.emplace_back(s, ca.back());
                --ds;
            }
            if (dt && find(t) != find(cb.back())) {
                merge(t, cb.back());
                ans.emplace_back(t, cb.back());
                --dt;
            }
            ca.pop_back(), cb.pop_back();
        }
    }
    if (tot != 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    for (auto [u, v]: ans) cout << u << ' ' << v << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
