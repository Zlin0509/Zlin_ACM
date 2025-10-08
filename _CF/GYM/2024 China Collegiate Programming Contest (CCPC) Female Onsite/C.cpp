//
// Created by Zlin on 2025/10/8.
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
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (const auto &c: s) {
        if (c == 'C') ++cnt1;
        if (c == 'P') ++cnt2;
    }
    int ans = min(cnt2, (cnt1 - 1) / 2);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
