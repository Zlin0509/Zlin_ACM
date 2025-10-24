//
// Created by Zlin on 2025/10/23.
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

constexpr ll mo = 998244353;

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vll a(n);
    for (ll &it: a) cin >> it;
    sort(a.begin(), a.end(), greater<ll>());
    if (a[k - 1] == 0) {
        cout << a[0] % mo << endl;
        return;
    }
    ll ans = 1;
    for (int i = 0; i < k; i++) ans = ans * a[i] % mo;
    for (int i = k; i + k - 2 < n; i += k - 1) {
        if (a[i + k - 2] == 0) break;
        ll tmp = 1;
        for (int j = 0; j < k - 1; j++) tmp = tmp * a[i + j] % mo;
        ans = ans * tmp % mo;
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
