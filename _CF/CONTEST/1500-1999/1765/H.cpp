//
// Created by 27682 on 2025/4/23.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2020;

int n, m, p[N], ans[N];
vi e1[N], e2[N];

int in[N], val[N];
vi pool[N];

inline bool check(int s, int x) {
    for (int i = 1; i <= n; i++) in[i] = val[i] = 0;
    for (int i = 1; i <= n; i++) {
        val[i] = p[i];
        for (int v: e2[i]) ++in[v];
    }
    val[s] = x;
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e2[u]) {
            val[v] = min(val[v], val[u]);
            --in[v];
            if (!in[v]) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        in[i] = 0;
        pool[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int v: e1[i]) {
            ++in[v];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            pool[val[i]].push_back(i);
        }
    }
    int now = 0, top = 1;
    while (now < n) {
        while (pool[top].empty()) ++top;
        int u = pool[top].back();
        pool[top].pop_back();
        ++now;
        if (now > top) return false;
        for (int v: e1[u]) {
            --in[v];
            if (!in[v]) pool[val[v]].push_back(v);
        }
    }
    return true;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e1[u].push_back(v);
        e2[v].push_back(u);
    }
    for (int i = 1, l, r, mid; i <= n; i++) {
        l = 1, r = p[i];
        while (l < r) {
            mid = l + r >> 1;
            if (check(i, mid)) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
