//
// Created by 27682 on 2025/11/4.
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

constexpr int N = 4e5 + 10;

int n, cnt;
ll a[N], b[N], dp[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[b[cnt = 0] = 0] = 2e18;
    for (int i = n; i; i--) if (a[i] < a[b[cnt]]) b[++cnt] = i;
    reverse(b + 1, b + cnt + 1);
    int l0 = 1, l1 = 1;
    for (int i = 1; i <= cnt; i++) {
        while ((a[b[i]] - 1) / a[b[l0]] + 1 > 2) ++l0;
        while ((a[b[i]] - 1) / a[b[l1]] + 1 > 3) ++l1;
        dp[i] = min({dp[i - 1] + 1, dp[l0 - 1] + 2, dp[l1 - 1] + 3});
    }
    cout << dp[cnt] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
