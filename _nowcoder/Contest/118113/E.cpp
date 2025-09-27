//
// Created by 27682 on 2025/9/27.
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
    int n;
    cin >> n;
    vector<pair<string, int> > a(n);
    int tag = 0;
    for (auto &[x, y]: a) {
        cin >> x >> y;
        if (x == "sensei") tag = y;
    }
    ll ans = tag;
    for (const auto &[x, y]: a) {
        if (y < tag) ans += y;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
