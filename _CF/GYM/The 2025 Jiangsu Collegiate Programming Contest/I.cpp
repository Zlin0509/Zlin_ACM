//
// Created by Zlin on 2025/10/25.
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

constexpr int N = 1e5 + 10;

map<array<int, 3>, int> mp[8];
int n, s[N][3];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> s[i][j];
        mp[0][{s[i][0], s[i][1], s[i][2]}]++;
        mp[1][{s[i][0], s[i][1], 0}]++;
        mp[2][{0, s[i][1], s[i][2]}]++;
        mp[3][{s[i][0], 0, s[i][2]}]++;
        mp[4][{s[i][0], 0, 0}]++;
        mp[5][{0, s[i][1], 0}]++;
        mp[6][{0, 0, s[i][2]}]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        vll val(7);
        val[0] = 0;
        val[1] = mp[1][{s[i][0], s[i][1], 0}] - 1;
        val[2] = mp[2][{0, s[i][1], s[i][2]}] - 1;
        val[3] = mp[3][{s[i][0], 0, s[i][2]}] - 1;
        val[4] = mp[4][{s[i][0], 0, 0}] - val[1] - val[3] - 1;
        val[5] = mp[5][{0, s[i][1], 0}] - val[1] - val[2] - 1;
        val[6] = mp[6][{0, 0, s[i][2]}] - val[2] - val[3] - 1;
        ll tmp = 0, sum = 0;
        for (int j = 1; j <= 3; j++) {
            tmp += val[j] * (val[j] - 1) / 2 + val[j] * sum;
            sum += val[j];
        }
        for (int j = 4; j <= 6; j++) {
            tmp += val[j] * sum;
            sum += val[j];
        }
        ans += tmp;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
