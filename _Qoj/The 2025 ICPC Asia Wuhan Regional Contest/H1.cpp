//
// Created by Zlin on 2025/11/7.
//

#include "bits/stdc++.h"
// #define endl '\n'
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
    vi a(n);
    for (int &it: a) cin >> it;
    while (1) {
        int x;
        cin >> x;
        int mx = 0;
        for (int it: a) mx = max(mx, it ^ x);
        cout << mx << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}