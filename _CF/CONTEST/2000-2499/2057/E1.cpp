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

int f[404][404][404], g[404][404][404];

inline void Zlin() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                f[i][j][k] = 2e9;
            }
        }
    }
    map<int, vector<pii> > mp;
    vi have;
    for (int i = 1, u, v, val; i <= m; i++) {
        cin >> u >> v >> val;
        mp[val].push_back({u, v});
        have.push_back(val);
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    reverse(have.begin(), have.end());
    for (int it: have) {
        for (auto [u, v]: mp[it]) {
            f[u][v][1] = f[v][u][1] = it;
            for (int i = 1; i <= n; i++) {
                if (i == v || i == u) continue;
                bool c1 = false, c2 = false;
                for (int k = m; k >= 0; k--) {
                    if (f[u][i][k] != 2e9) {
                        c1 = true;
                    }
                    if (f[v][i][k] != 2e9) {
                        c2 = true;
                    }
                    if (c1) {
                        f[v][i][k + 1] = f[i][v][k + 1] = it;
                    }
                    if (c2) {
                        f[u][i][k + 1] = f[i][u][k + 1] = it;
                    }
                }
            }
        }
        // for (int k = 1; k <= m; k++) {
        //     for (int i = 1; i <= n; i++) {
        //         for (int j = 1; j <= n; j++) {
        //             cout << f[i][j][k] << ' ';
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
    }
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << f[a][b][k] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
