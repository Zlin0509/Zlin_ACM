//
// Created by Zlin on 2025/8/8.
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

constexpr int N = 1e5 + 10;

int n, k;

struct node {
    int x, y;

    bool operator<(const node &b) const {
        return x * b.y >= y * b.x;
    }
};

inline void Zlin() {
    cin >> n >> k;
    vector<node> a(n), tmp;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    sort(a.begin(), a.end());
    vector<vector<node> > group;
    for (int i = 0; i < k; i++) tmp.emplace_back(a[i]);
    group.emplace_back(tmp);
    for (int i = k; i < n; i++) {
        tmp.clear();
        tmp.emplace_back(a[i]);
        group.emplace_back(tmp);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
