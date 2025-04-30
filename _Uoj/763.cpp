//
// Created by 27682 on 2025/4/21.
//
#include "bits/stdc++.h"

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

constexpr int N = 1e6 + 10;
const ull mask = mt19937_64(time(nullptr))();

inline ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

int n;
ull Hash[N];
vi e[N];
set<ull> have;

inline void dfs(int u, int fa) {
    Hash[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        Hash[u] += shift(Hash[v]);
    }
    have.insert(Hash[u]);
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << have.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}