//
// Created by 27682 on 2025/10/30.
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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll z = gcd(x, y);
    x /= z, y /= z;
    cout << min(a / x, b / y) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
