//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll fac[5010], inv[5010];

void dd() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 5000; i++)
        fac[i] = fac[i - 1] * i % mo;
    inv[5000] = qpow(fac[5000], mo - 2);
    for (int i = 4999; i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

ll comb(int n, int k) {
    return fac[n] * inv[k] % mo * inv[n - k] % mo;
}

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    vector f(n + 2, vll(n + 2, 0)), cnt(n + 2, vll(n + 2, 0));
    f[n + 1][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i][a[i]] = 1;
    }
    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n; j++)
            cnt[i][j] += cnt[i - 1][j];
    ll ans = 0, mx = 0;
    for (int l = n; l; l--) {
        for (int r = l + 1; r <= n + 1; r++) {
            if (cnt[r - 1][a[l]] - cnt[l - 1][a[l]] < k) continue;
            for (int z = 0; z < n; z++) {
                if (!f[r][z]) continue;
                f[l][z + 1] += f[r][z] * comb(cnt[r - 1][a[l]] - cnt[l - 1][a[l]] - 1, k - 1) % mo;
                mx = max(mx, (ll) z + 1);
            }
        }
    }
    for (int i = 1; i <= n + 1; i++)
        ans = (ans + f[i][mx]) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
