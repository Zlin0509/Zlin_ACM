//
// Created by 27682 on 2025/5/14.
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

int n, m, p;
int dis[401][401], val[401], vis[401];

inline void Zlin() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dis[i][j] = 2e9;
        dis[i][i] = 0;
        vis[i] = 0;
        val[i] = 2e9;
    }
    vi now;
    for (int i = 1, x; i <= p; i++) {
        cin >> x;
        now.push_back(x);
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ll ans = 2e18, tag;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            ll sum = 0;
            for (int v: now) sum += min(val[v], dis[j][v]);
            if (sum < ans) {
                ans = sum;
                tag = j;
            }
        }
        cout << ans << ' ';
        vis[tag] = 1;
        for (int v: now) val[v] = min(val[v], dis[tag][v]);
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
