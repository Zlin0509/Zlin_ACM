//
// Created by Zlin on 2025/10/22.
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

constexpr int N = 2010;

int n, a[N][N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] == (i ^ j)) {
                bool check = true;
                for (int k = 1; k <= n; k++) {
                    if ((a[k][i] ^ j) != a[k][j] && (a[k][i] ^ i) != a[k][j]) {
                        check = false;
                        break;
                    }
                }
                if (check) ans.emplace_back(i, j);
            }
        }
    }
    for (const auto &[x, y]: ans) cout << x << ' ' << y << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
