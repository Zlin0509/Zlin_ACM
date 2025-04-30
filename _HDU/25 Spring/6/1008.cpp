//
// Created by 27682 on 2025/4/11.
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
constexpr int N = 2e5;

ll fac[N + 10], inv;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;
    if (n == 1) {
        cout << 0 << ' ' << 1 << endl;
        return;
    }
    sort(a.begin(), a.end(), greater<int>());
    ll ans = 0, res = 0, ans2 = 1;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i - 1]) {
            ++cnt;
        } else {
            ans2 = ans2 * fac[cnt] % mo;
            cnt = 1;
        }
    }
    if (cnt >= 2) ans2 = ans2 * fac[cnt] % mo * inv % mo;
    res += a.back();
    a.pop_back();
    while (!a.empty()) {
        ans = (ans + res * a.back()) % mo;
        res = (res + a.back()) % mo;
        a.pop_back();
    }
    cout << ans << ' ' << ans2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    fac[0] = 1;
    inv = qpow(2, mo - 2);
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % mo;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}