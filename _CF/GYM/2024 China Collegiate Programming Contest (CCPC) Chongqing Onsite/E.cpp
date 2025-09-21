//
// Created by 27682 on 2025/9/15.
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

constexpr int N = 1e5 + 10;

int n, m, a[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) if (e[i].size() <= 1) ans = min(ans, a[i]);
    for (int i = 1; i <= n; i++) if (e[i].size() >= 2) ans = max(ans, a[i]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
