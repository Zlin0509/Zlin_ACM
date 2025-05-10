//
// Created by 27682 on 2025/5/10.
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

constexpr int N = 3e5 + 10;

int n, dep[N], siz[N];
vi e[N];

ll ans;

inline void dfs(int u,int fa) {
    ans += 1ll * (n - 1) * dep[u];
    ll cnt = 0;
    siz[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        cnt += 1ll * siz[u] * siz[v];
        siz[u] += siz[v];
    }
    ans -= 2ll * dep[u] * cnt;
    ans += siz[u] - 1;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dep[i] = siz[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = -1ll * n * (n - 1) / 2;
    dfs(1, 0);
    ll sr = 0, cntr = 0;
    vi val;
    for (int i = 1; i <= n; i++) {
        val.push_back(dep[i]);
        sr += dep[i], ++cntr;
    }
    sort(val.begin(), val.end());
    for (int it: val) {
        sr -= it;
        --cntr;
        ans -= sr - cntr * it;
    }
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
