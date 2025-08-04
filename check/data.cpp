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

int a[1010][11];

inline void Zlin() {
    int n = rng() % 10 + 1, m = rng() % 5 + 1, k = rng() % m + 1;
    k = min(k, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = rng() % 10 + 1;
        }
    }
    cout << n << ' ' << m << ' ' << k << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cout << 1 << endl;
    while (ttt--) Zlin();
    return 0;
}
