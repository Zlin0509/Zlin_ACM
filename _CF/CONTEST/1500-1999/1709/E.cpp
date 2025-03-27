//
// Created by 27682 on 2025/3/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;

int ans = 0;
int n, a[N], d[N];
vi e[N];
set<int> s[N];

void dfs(int u, int fa) {
    s[u].insert(d[u]);
    bool check = false;
    for (int v: e[u]) {
        if (v == fa) continue;
        d[v] = d[u] ^ a[v];
        dfs(v, u);
        if (s[u].size() < s[v].size()) swap(s[u], s[v]);
        for (int z: s[v])
            if (s[u].find(z ^ a[u]) != s[u].end())
                check = true;
        for (int z: s[v])
            s[u].insert(z);
    }
    if (check)
        ++ans, s[u].clear();
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
