//
// Created by 27682 on 2025/6/26.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector<int> vi;
typedef long long ll;

constexpr ll INF = 1e12;

int n, k, c[81];
ll f[81][81], val[81][11];
ll ans = INF;

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> f[i][j];
    for (int ttt = 1; ttt <= 5000; ttt++) {
        for (int i = 1; i <= n; i++) {
            c[i] = rng() % 2;
            for (int j = 0; j <= k; j++) val[i][j] = INF;
            val[i][0] = INF;
        }
        val[1][0] = 0;
        for (int dep = 0; dep < k; dep++) {
            for (int i = 1; i <= n; i++) val[i][dep + 1] = INF;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (c[i] == c[j]) continue;
                    val[j][dep + 1] = min(val[j][dep + 1], val[i][dep] + f[i][j]);
                }
            }
        }
        ans = min(ans, val[1][k]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
