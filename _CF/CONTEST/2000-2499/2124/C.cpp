//
// Created by 27682 on 2025/7/6.
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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] % a[i]) {
            ll tag = a[i] / gcd(a[i], a[i + 1]);
            ans = ans * tag / gcd(ans, tag);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
