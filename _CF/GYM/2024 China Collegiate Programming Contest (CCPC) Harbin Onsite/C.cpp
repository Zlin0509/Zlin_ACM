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

const char idx[4]{'N', 'E', 'S', 'W'};

inline void Zlin() {
    int n;
    cin >> n;
    vector<pair<char, int> > v(n), ans;
    for (auto &[x, y]: v) cin >> x >> y;
    int base = 0;
    while (idx[base] != v[0].first) base = (base + 1) % 4;
    for (int i = 0; i < n; i++) {
        auto [x, y] = v[i];
        if (idx[base] != x) {
            if (idx[(base + 1) % 4] == x) {
                ans.emplace_back('R', 0);
                base = (base + 1) % 4;
            } else {
                ans.emplace_back('L', 0);
                base = (base + 3) % 4;
            }
        }
        if (idx[base] == x) ans.emplace_back('Z', y);
    }
    cout << ans.size() << ' ' << v[0].first << endl;
    for (auto [x, y]: ans) {
        if (x == 'Z') cout << x << ' ' << y << endl;
        else cout << x << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
