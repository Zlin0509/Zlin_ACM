//
// Created by Zlin on 2025/8/4.
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

int n, m, k;
int a[1010][15], vis[1010];
ll ans;

inline void dfs(int dep, vi val) {
    if (dep == k) {
        ll res = 0;
        for (int it: val) res += it;
        ans = max(ans, res);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            vi tmp = val;
            for (int j = 0; j < val.size(); j++) tmp[j] = max(tmp[j], a[i][j]);
            dfs(dep + 1, tmp);
            vis[i] = 0;
        }
    }
}

inline void out(int dep, vi val) {
    if (dep == k) {
        ll res = 0;
        for (int it: val) res += it;
        if (ans == res) {
            for (int i = 1; i <= n; i++) cout << vis[i] << ' ';
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            vi tmp = val;
            for (int j = 0; j < val.size(); j++) tmp[j] = max(tmp[j], a[i][j]);
            out(dep + 1, tmp);
            vis[i] = 0;
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    ans = 0;
    k = min(k, m);
    vi tmp(m);
    dfs(0, tmp);
    out(0, tmp);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
