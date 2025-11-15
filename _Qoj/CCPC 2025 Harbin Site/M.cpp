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

constexpr int N = 1e5 + 5;

int n, cnt[2][N];
string a, b, c;

inline void Zlin() {
    cin >> n >> a >> b >> c;
    reverse(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        cnt[0][i] = cnt[1][i] = 0;
        if (c[i] == b[i]) {
            if (b[i] == '1')cnt[1][i] = 1;
            else cnt[0][i] = 1;
        }
        if (i) for (int j = 0; j < 2; j++) cnt[j][i] += cnt[j][i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            ans += cnt[1][n - i - 1];
        } else {
            ans += cnt[0][n - i - 1];
        }
        cout << ans << endl;
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
