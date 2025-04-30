//
// Created by 27682 on 2025/4/18.
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

int n, k, mo;
int f[101][31];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void Zlin() {
    cin >> n >> k >> mo;
    int ans = qpow(k, n);
    f[0][0] = 1;
    for (int s = 0; s < k; s++) {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++)
                f[i][j] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                if (2 * j % k != s % k) {
                    for (int l = 0; l < k; l++) {
                        f[i][(l + j) % k] = (f[i][(l + j) % k] + f[i - 1][l]) % mo;
                    }
                }
            }
        }
        ans = (ans - f[n][s] + mo) % mo;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
