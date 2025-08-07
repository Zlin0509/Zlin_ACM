//
// Created by Zlin on 2025/8/7.
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

constexpr int N = 1e6 + 5;
constexpr ll U = (1 << 30) - 1;

ll n, A, B, C;
ll f[3], g[3], h[3];

inline void dd(int i) {
    g[i % 3] = f[i % 3] xor ((65536 * f[i % 3]) & U);
    h[i % 3] = g[i % 3] xor (g[i % 3] / 32);
    f[i % 3] = h[i % 3] xor (2 * h[i % 3] & U) xor f[(i + 1) % 3] xor f[(i + 2) % 3];
}

inline void Zlin() {
    cin >> n >> A >> B >> C;
    f[0] = A & U, f[1] = B & U, f[2] = C & U;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dd(i);
        ll lx = i, rx = i + f[i % 3] % (n - i);
        ans ^= lx != rx;
    }
    cout << ans;
    for (int i = 1; i <= n - 1; i++) {
        dd(n + 3 * i - 3), dd(n + 3 * i - 2), dd(n + 3 * i - 1);
        ll l = min(f[n % 3] % n, f[(n + 1) % 3] % n), r = max(f[n % 3] % n, f[(n + 1) % 3] % n);
        ll d = f[(n + 2) % 3] % n + 1;
        if ((r - l + 1) % 2 == 0 && d % 2 == 1) ans ^= 1;
        cout << ans;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
