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

constexpr int N = 505;
constexpr ll mo = 1e9 + 7;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

struct Frac {
    ll a, b;

    Frac(ll _a = 0, ll _b = 1) {
        a = _a, b = _b;
        norm();
    }

    bool operator==(const Frac &other) const { return a * other.b == other.a * b; }
    bool operator<(const Frac &other) const { return a * other.b < other.b * a; }
    bool operator>(const Frac &other) const { return a * other.b > other.b * a; }

    void norm() {
        ll z = __gcd(a, b);
        a /= z, b /= z;
    }
} val[N][N];

int n, m, num;
int a[N], v[N];

ll dp[N][N >> 1];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] *= -1;
    for (int i = 0; i < m; i++) cin >> v[i];
    num = n / 2;
    sort(a, a + n);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) val[i][j] = Frac(a[j], v[i]);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Frac tmp = val[i][j];
            vll exp;
            for (int i1 = 0; i1 < m; i1++) {
                if (i1 == i) continue;
                int idx = lower_bound(val[i1], val[i1] + n, tmp) - val[i1] + 1;
                if (idx <= n) exp.emplace_back(idx * qpow(n, mo - 2) % mo);
            }
            for (int i1 = 0; i1 < m - 1; i1++) for (int j1 = 0; j1 <= m >> 1; j1++) dp[i1][j1] = 0;
            dp[0][0] = exp[0], dp[0][1] = (1 - exp[0] + mo) % mo;
            for (int i1 = 0; i1 < m - 2; i1++) {
                ll e1 = exp[i1 + 1], e2 = (1 - e1 + mo) % mo;
                for (int j1 = 0; j1 <= m >> 1; j1++) {
                    dp[i1 + 1][j1] = (dp[i1 + 1][j1] + dp[i1][j1] * e1 % mo) % mo;
                    dp[i1 + 1][j1 + 1] = (dp[i1 + 1][j1 + 1] + dp[i1][j1] * e2 % mo) % mo;
                }
            }
            cout << dp[m - 2][m >> 1] * qpow(n, mo - 2) % mo << endl;
            ans = (ans + dp[m - 2][m >> 1] * qpow(n, mo - 2) % mo) % mo;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cout << 1 * qpow(4, mo - 2) % mo << endl;
    while (ttt--) Zlin();
    return 0;
}
