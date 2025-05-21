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


constexpr int N = 1e5 + 10;

int f[N], ans;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fy] = fx;
    --ans;
}

inline void Zlin() {
    int n;
    cin >> n;
    vector<tuple<int, int, int> > v(n);
    for (auto &[c,l, r]: v) cin >> c >> l >> r;
    sort(v.begin(), v.end(), [&](auto x, auto y) {
        return get<2>(x) < get<2>(y);
    });
    ans = n;
    for (int i = 0; i < n; i++) f[i] = i;
    vi e[2];
    for (int i = 0; i < n; i++) {
        auto [c, l, r] = v[i];
        int lst = -1;
        while (1) {
            if (e[c].empty()) {
                if (~lst) e[c].push_back(lst);
                break;
            }
            int now = e[c].back();
            if (l <= get<2>(v[now])) {
                merge(now, i);
                if (!~lst) lst = now;
                e[c].pop_back();
            } else {
                if (~lst) e[c].push_back(lst);
                break;
            }
        }
        e[c ^ 1].push_back(i);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
