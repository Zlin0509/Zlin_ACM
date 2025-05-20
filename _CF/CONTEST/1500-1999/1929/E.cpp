//
// Created by 27682 on 2025/5/20.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;

int n;

struct edge {
    int v, id;
};

vector<edge> e[N];

int val[N];

int k;
pii s[22];

inline bool dfs(int u, int fa, int tag) {
    if (u == s[tag].second) return true;
    for (auto [v, id]: e[u]) {
        if (v == fa || !dfs(v, u, tag)) continue;
        val[id >> 1] |= 1 << tag;
        return true;
    }
    return false;
}

vi have;

int ans[1 << 21];

inline void Zlin() {
    cin >> n;
    have.clear();
    for (int i = 1; i <= n; i++) {
        val[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back({v, i * 2});
        e[v].push_back({u, i * 2 + 1});
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> s[i].first >> s[i].second;
        dfs(s[i].first, 0, i);
    }
    for (int i = 1; i < n; i++) have.push_back(val[i]);
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    for (int i = 0; i < 1 << k; i++) ans[i] = 40;
    ans[0] = 0;
    for (int i = 0; i < 1 << k; i++) for (int it: have) ans[i | it] = min(ans[i | it], ans[i] + 1);
    cout << ans[(1 << k) - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
