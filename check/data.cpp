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

constexpr int N = 1e5;
constexpr int INF = 1e9;

int idx[2] = {1, -1};

inline void Zlin() {
    int n = rng() % 1000;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int a = rng() % 100 * idx[rng() % 2], b = rng() % 100 * idx[rng() % 2], c = -a - b;
        cout << a << ' ' << b << ' ' << c << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cout << 1 << endl;
    while (ttt--) Zlin();
    return 0;
}
