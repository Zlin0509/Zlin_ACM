//
// Created by 27682 on 2025/4/23.
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

constexpr int N = 310;

int n, h, a[N];
ll f[N][N], ans[N];

inline void Zlin() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= n; j++) f[i][j] = 2e14;
        f[i][i] = h;
        ans[i] = 2e14;
    }
    if (!h) {
        cout << 0 << endl;
        return;
    }
    for (int i = 2, l, r; i <= n; i++) {
        r = a[i];
        for (int j = i - 1; j; j--) {
            l = a[j] + 1;
            if ((r - l) / 2 > h) break;
            for (int k = j; k < i; k++) {
                ll res = f[j][k] + f[k + 1][i] - h + (r - l) / 2;
                f[i][j] = min(f[i][j], res);
                f[j][i] = min(f[j][i], res);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i] = min(ans[i], f[j][i] + ans[j - 1]);
        }
    }
    cout << ans[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
