//
// Created by 27682 on 2025/7/22.
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
    int n, a, b;
    cin >> n >> a >> b;
    int k = n / (a + b);
    n -= k * (a + b);
    if (!k && n <= a) {
        cout << "Sayonara" << endl;
        return;
    }
    if (n <= a) {
        cout << n << endl;
        return;
    }
    cout << 0 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
