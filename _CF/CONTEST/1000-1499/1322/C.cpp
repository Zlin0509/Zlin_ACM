//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

constexpr int N = 5e5 + 10;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vll c(n), val(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        --u, --v;
        val[u] += c[v];
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
