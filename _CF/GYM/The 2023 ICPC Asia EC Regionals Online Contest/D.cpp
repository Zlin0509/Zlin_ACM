//
// Created by Zlin on 2024/10/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 10;

int f[N], siz[N];
int d[N];

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
    siz[fy] += siz[fx];
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1, d[i] = 0;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        d[u]++, d[v]++;
        merge(u, v);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += siz[find(i)] - 1 - d[i];
    if (!ans) {
        int mx = 1e7, tag = -1;
        for (int i = 1, z; i <= n; i++) {
            z = siz[find(i)];
            if (mx > z) {
                tag = find(i);
                mx = z;
            }
        }
        int mm = 1e7;
        for (int i = 1, z; i <= n; i++) {
            z = siz[find(i)];
            if (mm > z && find(i) != tag)
                mm = z;
        }
        ans = 2ll * mx * mm;
    }
    cout << ans / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}