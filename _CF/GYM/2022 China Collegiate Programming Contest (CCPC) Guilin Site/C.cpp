#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = double;
using ull = unsigned long long;
const int N = 1e6 + 5;
const int MAXN = 2e5 + 5;
const int M = 1e7 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ull base = 131;

struct Matrix {
    static const int n = 3;
    vector<array<ll, 3> > a;

    Matrix() {
        a.resize(n);
        for (int i = 0; i < n; i++) a[i][i] = 1;
    }

    array<ll, 3> &operator [](int i) {
        return a[i];
    }

    Matrix operator *(Matrix b) {
        Matrix c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return c;
    }
} m1, m2, dpl[N], dpr[N];

ll n, m, a[N], p1[N], p2[N];

void solve() {
    cin >> n >> m;
    ll sum = 0, d1 = 0, d2 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        p1[i] = (p1[i - 1] + a[i]) % mod;
        d1 = (d1 + p1[i]) % mod;
    }
    for (int i = n; i >= 1; i--) {
        p2[i] = (p2[i + 1] + a[i]) % mod;
        d2 = (d2 + p2[i]) % mod;
    }
    sum = sum % mod * n % mod;
    m1[0] = {2, 0, 0};
    m1[1] = {0, 2, 0};
    m1[2] = {1, 1, 4};
    m2[0] = {1, 1, 0};
    m2[1] = {1, 1, 0};
    m2[2] = {1, 1, 4};
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        dpl[i] = dpl[i - 1] * m1;
        dpr[i] = dpr[i - 1] * m2;
    }
    for (int i = 0; i <= m; i++) {
        Matrix mm = dpl[i] * dpr[m - i];
        ll res = (mm[0][0] * d1 + mm[1][0] * d2 + mm[2][0] * sum) % mod;
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
