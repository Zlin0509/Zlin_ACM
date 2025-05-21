//
// Created by 27682 on 2025/5/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;

int n, vis[N];
vi e[N];
ll s[N], k[N], r[N], val[N], ans[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> k[i] >> r[i];
        for (int j = 1, v; j <= r[i]; j++) {
            cin >> v;
            e[v].push_back(i);
        }
        ans[i] = k[i], val[i] = s[i];
    }
    priority_queue<pair<ll, int> > pq;
    for (int i = 1; i <= n; i++) pq.push({-ans[i], i});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: e[u]) {
            if (vis[v] || val[v] > ans[v]) continue;
            val[v] += ans[u];
            if (!--r[v]) {
                ans[v] = min(ans[v], val[v]);
                pq.push({-ans[v], v});
            }
        }
    }
    cout << ans[1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
