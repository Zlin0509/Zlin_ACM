//
// Created by Zlin on 2025/5/7.
//

#include "bits/stdc++.h"

#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 1010;
constexpr ll mo = 998244353;

int n, m, in1[N], in2[N];
ll a[N], tmp[N];
vi e[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in1[i] = in2[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        ++in2[u], ++in1[v];
    }
    for (int t = 1; t <= n; t++) {
        bool tag = false;
        for (int i = 1; i <= n; i++) tag |= a[i], tmp[i] = 0;
        if (!tag) {
            cout << t - 1 << endl;
            return;
        }
        for (int u = 1; u <= n; u++) {
            if (!a[u]) continue;
            --a[u];
            for (int v: e[u]) tmp[v] += 1;
        }
        for (int i = 1; i <= n; i++) a[i] += tmp[i];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in1[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            a[v] = (a[v] + a[u]) % mo;
            if (!--in1[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!in2[i]) {
            cout << (a[i] + n) % mo << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
