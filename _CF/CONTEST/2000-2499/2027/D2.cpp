//
// Created by Zlin on 2025/4/3.
//
#include"bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 1e9 + 7;
constexpr ll inf = 2e14;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1), b(m + 1);
    vector f(2, vll(n + 1)), g(2, vll(n + 1));
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i <= m; i++) cin >> b[i];
    g[0][0] = g[1][0] = 1;
    for (int i = 1; i <= n; i++) f[0][i] = inf, g[0][i] = 0;
    vll sum(n + 1);
    int now = 1;
    for (int i = 1; i <= m; ++i, now ^= 1) {
        for (int r = 1, l = 1, r1 = 0; r <= n; ++r) {
            f[now][r] = f[now ^ 1][r], g[now][r] = g[now ^ 1][r];
            while (l <= r && a[r] - a[l - 1] > b[i]) ++l;
            if (l <= r) {
                r1 = max(r1, l - 1);
                while (r1 < r - 1 && f[now][r1 + 1] == f[now][l - 1]) ++r1;

                if (f[now][r] > f[now][l - 1] + m - i) {
                    f[now][r] = f[now][l - 1] + m - i;
                    g[now][r] = (sum[r1] - sum[l - 1] + g[now][l - 1] + mo) % mo;
                } else if (f[now][r] == f[now][l - 1] + m - i) {
                    g[now][r] = (g[now][r] + sum[r1] - sum[l - 1] + g[now][l - 1] + mo) % mo;
                }
            }
            sum[r] = (sum[r - 1] + g[now][r]) % mo;
        }
    }
    if (f[now ^ 1][n] >= inf) {
        cout << -1 << "\n";
    } else {
        cout << f[now ^ 1][n] << " " << g[now ^ 1][n] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
