//
// Created by Zlin on 2025/4/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 5e5 + 10;

struct edge {
    int to, val;
};

int n;
vector<edge> e[N];

ll cnt1, cnt2;

inline void dfs(int u, int fa, ll val) {
    val ? ++cnt1 : ++cnt2;
    for (auto [v,w]: e[u]) {
        if (v == fa) continue;
        dfs(v, u, (val + w) % 2);
    }
}

inline void Zlin() {
    cin >> n;
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        w &= 1;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    ll ans = cnt1 * cnt1 * cnt1 + cnt2 * cnt2 * cnt2;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
