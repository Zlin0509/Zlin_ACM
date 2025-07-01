//
// Created by 27682 on 2025/7/1.
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

constexpr ll mo = 1e9 + 7;
constexpr int N = 1e5 + 10;

int n, f[N * 2], siz[N * 2], vis[N * 2], c[N];
pii a[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
    siz[fy] += siz[fx];
}

inline ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mo;
        x = x * x % mo;
        y >>= 1;
    }
    return res;
}

vi sx, sy;

int siz1[N * 2];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        sx.push_back(a[i].first);
        sy.push_back(a[i].second);
    }
    sort(sx.begin(), sx.end());
    sort(sy.begin(), sy.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    sy.erase(unique(sy.begin(), sy.end()), sy.end());
    for (int i = 0; i < sx.size() + sy.size(); i++) f[i] = i, siz[i] = 1;
    for (int i = 1; i <= n; i++) {
        a[i].first = lower_bound(sx.begin(), sx.end(), a[i].first) - sx.begin();
        a[i].second = lower_bound(sy.begin(), sy.end(), a[i].second) - sy.begin() + sx.size();
        merge(a[i].first, a[i].second);
    }
    for (int i = 1; i <= n; i++) siz1[find(a[i].first)]++;
    ll ans = 1;
    for (int i = 0, cnt, tot; i < sx.size() + sy.size(); i++) {
        if (vis[find(i)]) continue;
        vis[find(i)] = 1;
        tot = siz[find(i)];
        cnt = siz1[find(i)];
        ans = ans * (cnt + 1 == tot ? (qpow(2, tot) - 1 + mo) % mo : qpow(2, tot)) % mo;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
