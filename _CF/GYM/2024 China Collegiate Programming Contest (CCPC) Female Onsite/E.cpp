//
// Created by Zlin on 2025/10/8.
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

constexpr int N = 2e5 + 10;

int n;
vi e[N], bel[N], ans[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear(), ans[i].clear(), bel[i].clear();
    for (int i = 1, c, x; i <= n; i++) {
        cin >> c;
        while (c--) {
            cin >> x;
            e[i].emplace_back(x);
            bel[x].emplace_back(i);
        }
    }
    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const int &v: e[u]) {
            while (!bel[v].empty()) {
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
