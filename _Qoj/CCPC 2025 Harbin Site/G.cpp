//
// Created by Zlin on 2025/11/15.
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

constexpr int N = 1010;

int n, m;
ll a[N][N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    ll ans = 0, tmp;
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        for (int j = m; j; j--) {
            if (a[i][j] < 0) {
                tmp += a[i][j];
                a[i][j] = 0;
            } else {
                ll k = min(a[i][j], -tmp);
                a[i][j] -= k, tmp += k;
            }
        }
        ans -= tmp;
        if (i != n) for (int j = 1; j <= m; j++) a[i + 1][j] += a[i][j];
        else for (int j = 1; j <= m; j++) ans += a[i][j];
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
