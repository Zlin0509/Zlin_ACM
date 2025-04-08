//
// Created by 27682 on 2025/4/8.
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

inline void Zlin() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector a(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '#';
        }
    }
    vector sum(n + 1, vi(m + 1)), sus(n + 1, vi(m + 1)), f(n + 1, vi(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1] + a[i][j];
            sus[i][j] = sus[i - 1][j - 1] + a[i][j];
        }
    }
    auto cal = [&](int x, int y) {
        int res = 0;
        if (y + k > n) res = sus[x - y - k + n][n];
        else res = sus[x][y + k];
        if (x - k < 1) res -= sus[0][y - x + k - 1];
        else res -= sus[x - k - 1][y - 1];
        return res;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1, val; j <= m; j++) {
            val = sum[i][min(n, j + k)] + sum[i][j - 1] + f[i - 1][j] - cal(i, j);
            f[i][j] = val;
            ans = max(ans, val);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
