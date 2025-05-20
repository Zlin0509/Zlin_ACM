//
// Created by 27682 on 2025/5/20.
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

constexpr int N = 3e5 + 10;

struct card {
    int s, t;
};

int n, m;
vector<card> a, b;
vi sx, tx;


inline void Zlin() {
    cin >> n >> m;
    sx.clear(), tx.clear();
    a.assign(n, card());
    b.assign(m, card());
    for (int i = 0; i < n; i++) {
        cin >> a[i].s;
        sx.push_back(a[i].s);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].t;
        tx.push_back(a[i].t);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].s;
        sx.push_back(b[i].s);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].t;
        tx.push_back(b[i].t);
    }
    sort(sx.begin(), sx.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    sort(tx.begin(), tx.end());
    tx.erase(unique(tx.begin(), tx.end()), tx.end());
    for (auto &[s, t]: a) {
        s = lower_bound(sx.begin(), sx.end(), s) - sx.begin();
        t = lower_bound(tx.begin(), tx.end(), t) - tx.begin();
    }
    for (auto &[s, t]: b) {
        s = lower_bound(sx.begin(), sx.end(), s) - sx.begin();
        t = lower_bound(tx.begin(), tx.end(), t) - tx.begin();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
