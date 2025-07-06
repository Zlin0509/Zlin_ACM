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
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll mx = 1e15, ans = 1e15, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            ll tmp = sum;
            tmp += min(mx, a[i] + a[i + 1]);
            ans = min(ans, tmp);
        }
        mx = min(mx, a[i]);
        sum += mx;
    }
    ans = min(ans, sum);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
