//
// Created by Zlin on 2024/10/19.
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

const int N = 3e5 + 5;
const ll inf = 1e17;

int n, m;

struct edge {
    int u, v, val;

    bool operator<(const edge &x) const {
        return val < x.val;
    }
};

int f[N];

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    f[fx] = fy;
    return true;
}

vector<edge> all;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v, val; i <= m; i++) {
        cin >> u >> v >> val;
        all.push_back({u, v, val});
    }
    sort(all.begin(), all.end());
    for (int i = 1; i <= n; i++) f[i] = i;
    int top1 = 0, top2 = 0, x, y, val;
    for (edge it: all) {
        x = it.u, y = it.v, val = it.val;
        if (merge(x, y)) {
            if (val > top1) {
                top2 = top1;
                top1 = val;
            } else if (val > top2) {
                top2 = val;
            }
        }
        if (find(1) == find(n)) {
            break;
        }
    }
    cout << top1 + top2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}