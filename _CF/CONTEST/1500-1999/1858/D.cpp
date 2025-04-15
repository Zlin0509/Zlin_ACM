//
// Created by 27682 on 2025/4/14.
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

constexpr int N = 3010;
int f[2][N][N], st[2][N][N], a[N], lx[N];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        lx[i] = -1;
        for (int j = 0; j <= n; j++) {
            f[0][i][j] = f[1][i][j] = 0;
            st[0][i][j] = st[1][i][j] = 0;
        }
    }
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    f[a[n]][n][0] = 1;
    f[a[n] ^ 1][n][1] = 1;
    for (int i = n; i; i--) {
        for (int j = 1; j <= k; j++)
            f[a[i] ^ 1][i][j] = f[a[i] ^ 1][i + 1][j - 1] + 1;
        for (int j = 0; j <= k; j++)
            f[a[i]][i][j] = f[a[i]][i + 1][j] + 1;
        for (int j = 1; j <= k; j++) {
            f[0][i][j] = max(f[0][i][j], f[0][i][j - 1]);
            f[1][i][j] = max(f[1][i][j], f[1][i][j - 1]);
        }
    }
    for (int i = n - 1; i; i--) {
        for (int j = 0; j <= k; j++) {
            f[0][i][j] = max(f[0][i][j], f[0][i + 1][j]);
            f[1][i][j] = max(f[1][i][j], f[1][i + 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0, l, r; j <= k; j++) {
            l = f[0][i][j];
            r = f[0][i][j] + i;
            lx[l] = max(lx[l], f[1][r][k - j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        for (int len = 0; len <= n; len++) {
            if (lx[len] != -1) ans = max(ans, len * i + lx[len]);
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
