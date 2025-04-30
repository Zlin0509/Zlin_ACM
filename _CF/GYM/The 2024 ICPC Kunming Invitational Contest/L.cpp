//
// Created by Zlin on 2024/10/5.
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

struct node {
    int x, y;

    bool operator<(const node &a) const {
        if (x != a.x) return x < a.x;
        return y > a.y;
    }
};

inline void Zlin() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<node> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end());
    ll ans = (ll) (q + 1) * (p + 1) * (q + p) / 2ll;
    vi ly(n + 1);
    for (int i = 0; i <= n; i++) ly[i] = q;
    ly[0] = -1;
    for (auto it: a) {
        if (it.x >= p || it.y >= q) continue;
        int t = lower_bound(ly.begin(), ly.end(), it.y) - ly.begin();
        ans -= (ll) (p - it.x) * (ly[t] - it.y);
        ly[t] = it.y;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}