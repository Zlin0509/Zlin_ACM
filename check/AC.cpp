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

int n;
vll a, b, c, sa, sb, sc;


inline void read() {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    sa.assign(n, 0);
    sb.assign(n, 0);
    sc.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
}

inline void Zlin() {
    read();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sa[n - 1] = a[n - 1];
    sb[n - 1] = b[n - 1];
    sc[n - 1] = c[n - 1];
    for (int i = n - 2; ~i; i--) {
        sa[i] = a[i] + sa[i + 1];
        sb[i] = b[i] + sb[i + 1];
        sc[i] = c[i] + sc[i + 1];
    }
    ll ans = 1e18;
    for (int i = a[0]; i <= a[n - 1]; i++) {
        for (int j = b[0]; j <= b[n - 1]; j++) {
            int k = -i - j;
            ll tmp = 0;
            for (int z = 0; z < n; z++) {
                if (a[z] > i) tmp += a[z] - i;
                if (b[z] > j) tmp += b[z] - j;
                if (c[z] > k) tmp += c[z] - k;
            }
            ans = min(ans, tmp);
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
