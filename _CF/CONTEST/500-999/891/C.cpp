//
// Created by 27682 on 2025/6/30.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 5e5 + 10;

int n, m, q;


struct Edge {
    int u, v, fu, fv;
    int w, id;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
} line[N];

int fa[N];

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    fa[fy] = fx;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> line[i].u >> line[i].v >> line[i].w;
        line[i].id = i;
    }
    sort(line + 1, line + m + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m;) {
        int j = i;
        do {
            line[j].fu = find(line[j].u);
            line[j].fv = find(line[j].v);
        } while (++j <= m && line[j].w == line[i].w);
        while (i < j) {
            merge(line[i].u, line[i].v);
            ++i;
        }
    }
    sort(line + 1, line + m + 1, [&](const Edge &a, const Edge &b) {
        return a.id < b.id;
    });
    for (int i = 1; i <= n; i++) fa[i] = i;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<array<int, 3> > v;
        for (int i = 1, id; i <= k; i++) {
            cin >> id;
            v.push_back({line[id].w, line[id].fu, line[id].fv});
        }
        sort(v.begin(), v.end());
        bool check = true;
        for (int i = 0, j; i < k && check;) {
            j = i;
            while (j < k && v[j][0] == v[i][0]) {
                if (find(v[j][1]) == find(v[j][2])) check = false;
                merge(v[j][1], v[j][2]);
                ++j;
            }
            while (i < j) {
                fa[v[i][1]] = v[i][1], fa[v[i][2]] = v[i][2];
                ++i;
            }
        }
        cout << (check ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
