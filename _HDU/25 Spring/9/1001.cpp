//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int f[100][100][200];

inline void Zlin() {
    int t, n, m;
    cin >> t >> n >> m;
    vi a;
    a.push_back(0);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(n * t);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * t; j++) {
            for (int k = 0; k <= m; k++) {
                f[i][j][k] = 2e9;
            }
        }
    }
    f[0][0][0] = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j <= n * t; j++) {
            for (int k = 0; k <= n * t; k++) {
                for (int z = 0; z <= m; z++) {
                    if (z + abs(a[i] - j) > m) continue;
                    f[i][j][z + abs(a[i] - j)] = min(f[i][j][z + abs(a[i] - j)], f[i - 1][k][z] + (j - k) * (j - k));
                }
            }
        }
    }
    int ans = 2e9;
    for (int j = 0; j <= n * t; j++) {
        for (int k = 0; k <= m; k++) {
            ans = min(ans, f[n - 1][j][k] + (n * t - j) * (n * t - j));
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
