//
// Created by Zlin on 2024/9/26.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int maxn = 5050;

int n, m, f[maxn][maxn], a[maxn], b[maxn];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            f[i][j] = -1e9;
        }
        a[i] = 0;
    }
    for (int i = 1, l, r; i <= m; ++i) {
        cin >> l >> r;
        a[l] = r;
    }
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            int p = a[i];
            for (int j = 0; j < i; ++j) {
                for (int k = 1; k <= p - i; ++k) {
                    f[p][j + k] = max(f[p][j + k], f[i - 1][j] + (p - i + 1 - k) * j);
                }
            }
            i = p;
        } else {
            for (int j = 0; j <= i; ++j) {
                f[i][j] = f[i - 1][j] + j;
                if (j) {
                    f[i][j] = max(f[i][j], f[i - 1][j - 1]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, f[n][i] + i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}