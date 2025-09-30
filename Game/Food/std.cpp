//
// Created by 27682 on 2025/9/30.
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

int n, k;

struct Node {
    ll a, b, c;
    int id;

    bool operator<(const Node &x) const {
        if (a != x.a) return a < x.a;
        if (b + c != x.b + x.c) return b + c < x.b + x.c;
        return id > x.id;
    }
};

inline void Zlin() {
    cin >> n >> k;
    vector<Node> v;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a, b, c, i + 1);
    }
    sort(v.begin(), v.end());
    while (k--) {
        cout << v.back().id << endl;
        v.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
