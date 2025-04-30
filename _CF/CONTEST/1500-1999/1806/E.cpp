//
// Created by 27682 on 2025/4/21.
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

constexpr ll N = 1e5 + 5;

int n, q;
int a[N], f[N], d[N], c[N], idx[N];
ll s[N], used[N][501];

inline ll cal(int x, int y) {
    if (x == y) return s[x];
    if (c[d[x]] <= 500) {
        if (used[x][idx[y]]) return used[x][idx[y]];
        return used[x][idx[y]] = cal(f[x], f[y]) + (ll) a[x] * a[y];
    }
    return cal(f[x], f[y]) + (ll) a[x] * a[y];
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
        s[i] = s[f[i]] + (ll) a[i] * a[i];
        d[i] = d[f[i]] + 1;
        idx[i] = ++c[d[i]];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << cal(x, y) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
