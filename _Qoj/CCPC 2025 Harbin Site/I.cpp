//
// Created by Zlin on 2025/11/15.
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

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3> > v(n + m);
    for (int i = 0; i < n + m; i++) cin >> v[i][0] >> v[i][1] >> v[i][2];
    sort(v.begin(), v.end());
    map<array<int, 3>, int> mp;
    for (int i = 0; i < n + m; i++) {
        if (i < n + m && v[i] == v[i + 1]) {
            ++i;
            continue;
        }
        mp[v[i]] = 1;
    }
    map<int, int> cnt[3];
    for (const auto it: mp) {
        const auto [x, y, z] = it.first;
        cnt[0][x]++;
        cnt[1][y]++;
        cnt[2][z]++;
    }
    for (const auto &it: cnt) {
        for (const auto &val: it) {
            if (val.second & 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
