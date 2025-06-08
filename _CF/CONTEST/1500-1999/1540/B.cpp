//
// Created by 27682 on 2025/6/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool a[110], mp[32][110][110], tmp[110];

int n, m, T;

inline void Zlin() {
    cin >> n >> m >> T;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        mp[0][u][v] = true;
    }
    for (int z = 1; z < 32; z++)
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    mp[z][i][j] |= mp[z - 1][i][k] & mp[z - 1][k][j];
    while (T--) {
        int x, k;
        cin >> x >> k;
        for (int i = 1; i <= n; i++) a[i] = false;
        a[x] = true;
        int l = 0;
        while (k) {
            if (k & 1) {
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        tmp[j] |= a[i] & mp[l][i][j];
                for (int i = 1; i <= n; i++) a[i] = tmp[i], tmp[i] = false;
            }
            k >>= 1;
            ++l;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (a[i]) ++cnt;
        cout << cnt << ' ';
        for (int i = 1; i <= n; i++) if (a[i]) cout << i << ' ';
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
