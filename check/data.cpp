//
// Created by Zlin on 2025/8/3.
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

constexpr ll N = 8e18;
constexpr ll INF = 1e18;

inline void Zlin() {
    int n = rng() % 1000 + 1, m = rng() % (n * (n - 1) / 3) + 1;
    cout << n << ' ' << m << endl;
    set<pii> edge;
    while (edge.size() < m) {
        int x = rng() % n + 1, y = rng() % n + 1;
        if (x != y) edge.insert({min(x, y), max(x, y)});
    }
    for (const auto [x, y]: edge) cout << x << ' ' << y << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cout << 1 << endl;
    while (ttt--) Zlin();
    return 0;
}
