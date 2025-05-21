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

int n, m, p, b;
int t1[N], t2[N], dis[N], vis[N], type[N], val[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        val[i] = 0;
        type[i] = 0;
        vis[i] = 0;
        t1[i] = t2[i] = 0;
        dis[i] = 2e9;
    }
    cin >> p >> b;
    for (int i = 1, x; i <= p; i++) {
        cin >> x;
        t1[x] = 1;
    }
    for (int i = 1, x; i <= b; i++) {
        cin >> x;
        t2[x] = 1;
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (t1[1]) {
        cout << "YES" << endl;
        return;
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v: e[u]) {
            if (!t2[v] || dis[v] <= dis[u] + 1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (t2[i]) {
            type[i] = 1;
            for (int v: e[i]) {
                if (t2[v]) {
                    type[i] = 2;
                    break;
                }
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (t1[i]) {
            int res = 0;
            for (int v: e[i]) {
                if (type[v]) {
                    if (type[v] == 1) {
                        res = max(res, 1);
                    } else {
                        res = max(res, (int) 2e5);
                    }
                }
            }
            val[i] = res;
            sum += val[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (t1[i]) {
            sum -= val[i];
            for (int v: e[i]) {
                if (v == 1 || (dis[v] != 2e9 && t2[v] && sum >= dis[v])) {
                    cout << "YES" << endl;
                    return;
                }
            }
            sum += val[i];
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
