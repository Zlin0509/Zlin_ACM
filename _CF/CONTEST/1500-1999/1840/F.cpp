//
// Created by 27682 on 2025/4/16.
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
    int n, m, r;
    cin >> n >> m >> r;
    vector f(n + 1, vector(m + 1, vector(r + 1, 0)));
    vector<tuple<int, int, int> > op;
    for (int i = 1, t, d, cor; i <= r; i++) {
        cin >> t >> d >> cor;
        op.push_back({t, d, cor});
    }
    // 初始化0，0
    f[0][0][0] = true;
    vi tag(r + 1);
    for (auto [t, d, cor]: op) {
        if (t >= 0 && t <= r && ((d == 1 && cor == 0) || (d == 2 && cor == 0))) {
            tag[t] = 1;
        }
    }
    for (int k = 1; k <= r; k++) {
        if (tag[k]) continue;
        if (k) f[0][0][k] |= f[0][0][k - 1];
    }

    // 初始化第0行
    for (int j = 1; j <= m; j++) {
        tag.assign(r + 1, 0);
        for (auto [t, d, cor]: op) {
            if (t - j >= 0 && t - j <= r && ((d == 1 && cor == 0) || (d == 2 && cor == j))) {
                tag[t - j] = 1;
            }
        }
        for (int k = 0; k <= r; k++) {
            if (tag[k]) continue;
            f[0][j][k] |= f[0][j - 1][k];
            if (k) f[0][j][k] |= f[0][j][k - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        // 初始化每行第一个
        tag.assign(r + 1, 0);
        for (auto [t, d, cor]: op) {
            if (t - i >= 0 && t - i <= r && ((d == 1 && cor == i) || (d == 2 && cor == 0))) {
                tag[t - i] = 1;
            }
        }
        for (int k = 0; k <= r; k++) {
            if (tag[k]) continue;
            f[i][0][k] |= f[i - 1][0][k];
            if (k) f[i][0][k] |= f[i][0][k - 1];
        }

        for (int j = 1; j <= m; j++) {
            tag.assign(r + 1, 0);
            for (auto [t, d, cor]: op) {
                if (t - i - j >= 0 && t - i - j <= r && ((d == 1 && cor == i) || (d == 2 && cor == j))) {
                    tag[t - i - j] = 1;
                }
            }
            for (int k = 0; k <= r; k++) {
                if (tag[k]) continue;
                f[i][j][k] |= f[i - 1][j][k];
                f[i][j][k] |= f[i][j - 1][k];
                if (k) f[i][j][k] |= f[i][j][k - 1];
            }
        }
    }
    for (int k = 0; k <= r; k++) {
        if (f[n][m][k]) {
            cout << n + m + k << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
