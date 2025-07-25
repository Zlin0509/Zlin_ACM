//
// Created by 27682 on 2025/7/16.
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

constexpr int N = 5e5 + 10, M = 1e5 + 10;

int n, m, k;

struct Line {
    int u, v, val;
} lines[M];

struct Edge {
    int to, val, id;
};

vector<Edge> e[N];

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1, u, v, val; i <= m; i++) {
        cin >> u >> v >> val;
        if (u > v) swap(u, v);
        lines[i] = {u, v, val};
        e[u].emplace_back(v, val, i);
        e[v].emplace_back(u, val, i);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
