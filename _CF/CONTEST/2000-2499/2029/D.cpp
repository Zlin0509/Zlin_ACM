//
// Created by Zlin on 2024/12/9.
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
int n, m;
int f[N];
set<int> e[N];

struct op {
    int a, b, c;
};

vector<op> ans;

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void Zlin() {
    cin >> n >> m;

    ans.clear();
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        e[i].clear();
    }

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        e[x].insert(y);
        e[y].insert(x);
    }
    for (int i = 1, a, b, c; i <= n; i++) {
        a = i;
        while (e[i].size() >= 2) {
            b = *e[i].begin();
            e[b].erase(e[b].find(i));
            e[i].erase(e[i].begin());

            c = *e[i].begin();
            e[c].erase(e[c].find(i));
            e[i].erase(e[i].begin());

            ans.push_back({a, b, c});

            if (e[b].find(c) == e[b].end()) {
                e[b].insert(c);
                e[c].insert(b);
            } else {
                e[b].erase(e[b].find(c));
                e[c].erase(e[c].find(b));
            }
        }
    }
    int tl = 0, tr = 0;
    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) continue;
        merge(i, *e[i].begin());
        if (!tl)tl = i, tr = *e[i].begin();
    }
    if (!tl && !tr) {
        cout << ans.size() << '\n';
        for (auto it: ans) cout << it.a << ' ' << it.b << ' ' << it.c << '\n';
        return;
    }
    for (int i = 1, fx, fy; i <= n; i++) {
        fx = find(i), fy = find(tl);
        if (fx == fy) continue;
        merge(fx, fy);
        ans.push_back({i, tl, tr});
        tr = i;
    }
    cout << ans.size() << '\n';
    for (auto it: ans) cout << it.a << ' ' << it.b << ' ' << it.c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}