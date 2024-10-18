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

const ll mo = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return qpow(a, mo - 2);
}

const int N = 1e6 + 5;
int n;
int f[N], siz[N];

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
    siz[fy] += siz[fx];
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    vector<pii> a(n - 1), b(n - 1);
    for (auto &[x, y]: a)
        cin >> x >> y;
    for (auto &[x, y]: b)
        cin >> x >> y;
    ll res = 1;
    for (int i = 0; i < n - 1; i++) {
        int x = find(a[i].first), y = find(a[i].second);
        int xx = find(b[i].first), yy = find(b[i].second);
        if (!(x == xx && y == yy || x == yy && y == xx)) {
            res = 0;
            break;
        }
        res = res * inv(1ll * siz[x] * siz[y] % mo) % mo;
        merge(x, y);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}