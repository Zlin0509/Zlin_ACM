//
// Created by 27682 on 2025/3/25.
//
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr ll mo = 998244353;

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
    vector f0(32, vi(32, 0)), f1(32, vi(32, 0));
    for (int it: a) {
        for (int i = 30, cnt = 0; ~i; i--) {
            if (it >> i & 1) f1[i][cnt++]++;
            else f0[i][cnt]++;
        }
    }
    ll ans = 0, val;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            val = f0[i][j] * f1[i][j];
            val = val * 2 * j + val * (2 * j + 1);
            ans = (ans + val) % mo;
        }
    }
    ans = ans * 2 % mo;
    cout << ans << ' ';
    ans = ans * qpow(1ll * n * n, mo - 2) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
