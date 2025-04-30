//
// Created by 27682 on 2025/4/7.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 1e9 + 7;

vector<vll> mul(vector<vll> a, vector<vll> b) {
    vector res(2, vll(2));
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < 2; j++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mo) % mo;
    return res;
}

vector<vll> qpow(vector<vll> f, int n) {
    vector res(2, vll(2));
    res[0][0] = res[1][1] = 1;
    while (n) {
        if (n & 1) res = mul(res, f);
        f = mul(f, f);
        n >>= 1;
    }
    return res;
}

inline void Zlin() {
    int m, n;
    cin >> m >> n;
    vll s(m + 1), l(m + 1);
    for (int i = 1; i <= m; i++) cin >> s[i];
    for (int i = 1; i <= m; i++) cin >> l[i];
    vector f(2, vll(2));
    for (int i = 1; i <= m; i++) {
        f[0][0] = (f[0][0] + s[i] * (s[i] + l[i]) % mo) % mo, f[0][1] = (f[0][1] + s[i] * s[i] % mo) % mo;
        f[1][0] = (f[1][0] + l[i] * (s[i] + l[i]) % mo) % mo, f[1][1] = (f[1][1] + l[i] * s[i] % mo) % mo;
    }
    vector res = qpow(f, n - 1);
    ll f0 = (s[1] * res[0][0] % mo + l[1] * res[0][1] % mo) % mo;
    ll f1 = (s[1] * res[1][0] % mo + l[1] * res[1][1] % mo) % mo;
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + f0 * (s[i] + l[i]) % mo + f1 * s[i] % mo) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
