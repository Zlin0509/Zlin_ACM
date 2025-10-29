//
// Created by Zlin on 2025/8/3.
//

#include "bits/stdc++.h"
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
    int id;

    Frac(ll _a = 0, ll _b = 1, int _id = 0) {
        a = _a, b = _b, id = _id;
        norm();
    }

    bool operator==(const Frac &o) const { return a == o.a && b == o.b; }
    bool operator<(const Frac &o) const { return a * o.b < o.a * b; }
    bool operator>(const Frac &o) const { return o < *this; }

    void norm() {
        ll z = __gcd(a, b);
        a /= z, b /= z;
    }
};

int n, m, num;
int a[N], v[N];
ll f[N], val[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] *= -1;
    for (int i = 0; i < m; i++) cin >> v[i];
    vector<Frac> p;
    for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) p.emplace_back(a[i], v[j], j);
    sort(p.begin(), p.end());
    ll invn = qpow(n, mo - 2);
    n = n * m;
    f[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int id = p[i].id;
        ll tmp = val[id], inv = qpow((1 - tmp + mo) % mo, mo - 2);
        f[0] = inv * f[0] % mo;
        for (int j = 1; j < m; j++) f[j] = inv * (f[j] - tmp * f[j - 1] % mo + mo) % mo;
        ans = (ans + f[m >> 1] * p[i].a % mo * qpow(p[i].b, mo - 2) % mo) % mo;
        val[id] = (val[id] + invn) % mo;
        tmp = val[id], inv = (1 - tmp + mo) % mo;
        f[m] = 0;
        for (int j = m; j; j--) f[j] = (inv * f[j] % mo + tmp * f[j - 1] % mo) % mo;
        f[0] = inv * f[0] % mo;
    }
    cout << ans * invn % mo << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cout << 1 * qpow(4, mo - 2) % mo << endl;
    while (ttt--) Zlin();
    return 0;
}
