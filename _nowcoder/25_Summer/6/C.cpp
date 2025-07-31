//
// Created by Zlin on 2025/7/31.
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

constexpr int N = 5e5 + 10;
constexpr ll mo = 998244353;

ll f[2][N], ans[N], sum[N];

inline void Zlin() {
    f[1][1] = 1;
    ans[1] = 1;
    cout << f[1][1] << endl;
    for (int i = 2; i <= 10; i++) {
        int o = i & 1;
        ll res = 0;
        for (int j = 1; j <= i; j++) {
            f[o][j] = f[o ^ 1][j - 1] + f[o ^ 1][j] * (i - 1);
            cout << f[o][j] << ' ';
            res += f[o][j] * pow(j, 3);
        }
        cout << endl;
        ans[i] = res;
    }
    for (int i = 1; i <= 10; i++) sum[i] = sum[i - 1] + pow(i, 3);
    for (int i = 1; i <= 10; i++) cout << sum[i] << ' ';
    cout << endl;
    for (int i = 1; i <= 10; i++) cout << i << ' ' << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
