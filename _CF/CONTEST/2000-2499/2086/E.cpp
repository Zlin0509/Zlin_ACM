//
// Created by 27682 on 2025/9/10.
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

ll l, r, k, val[32], cnt[32], dp[32][2][90][2];

inline ll dfs(int pos, int op1, int sum, int op2) {
    if (sum > k) return 0;
    if (!pos) return sum == k;
    if (dp[pos][op1][sum][op2] != -1) return dp[pos][op1][sum][op2];
    int check = 0;
    if (op2) check = 0;
    else if (op1) check = cnt[pos];
    else check = 4;
    ll ans = 0;
    for (int i = 0; i <= check; i++) ans += dfs(pos - 1, op1 && i == check, sum + i, i == 4 || op2);
    return dp[pos][op1][sum][op2] = ans;
}

inline ll cal(ll tag) {
    memset(cnt, 0, sizeof cnt);
    memset(dp, -1, sizeof dp);
    for (int i = 30; i; i--) {
        while (tag >= val[i]) {
            tag -= val[i];
            ++cnt[i];
        }
    }
    return dfs(30, 1, 0, 0);
}

inline void Zlin() {
    cin >> l >> r >> k;
    cout << cal(r) - cal(l - 1) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 1; i < 32; i++) val[i] = val[i - 1] * 4 + 1;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
