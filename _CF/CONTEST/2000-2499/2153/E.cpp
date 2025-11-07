//
// Created by 27682 on 2025/11/4.
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

constexpr int N = 1e7 + 5;

vi primes, fac[N];
bool is_p[N];

inline void prework() {
    fill(is_p, is_p + N, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_p[i]) primes.emplace_back(i);
        for (const auto &j: primes) {
            if (i * j > N) break;
            is_p[i * j] = false;
            if (i % j == 0) break;
        }
    }
    primes.emplace_back(N);
}

ll val[N];

inline ll cal(ll n, int k) {
    ll res = 0;
    for (ll i = k; i <= n; i *= k) res += n / i;
    return res;
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    int l = *(upper_bound(primes.begin(), primes.end(), n) - 1), r = n - 1;
    for (int i = l; i <= r; i++) val[i] = 1e12;
    vi mx;
    for (int i = 1, tmp; i * i <= n; i++) {
        tmp = n / i;
        mx.emplace_back(*(upper_bound(primes.begin(), primes.end(), tmp) - 1));
    }
    for (int i = l; i <= r; i++) {
        for (const auto &it: mx) {
            ll cn = cal(n, it), cx = cal(i, it);
            if (cn != cx) val[i] = min(val[i], cx);
        }
        for (const auto &it: primes) {
            if (1ll * it * it > m) break;
            ll cn = cal(n, it), cx = cal(i, it);
            ll tag = it;
            for (int j = 1; tag <= m; tag *= it, j++) {
                ll vn = cn / j, vx = cx / j;
                if (vn != vx) val[i] = min(val[i], vx);
            }
        }
    }
    ll ans = 0;
    for (int i = l; i <= r; i++) ans += val[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    prework();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
