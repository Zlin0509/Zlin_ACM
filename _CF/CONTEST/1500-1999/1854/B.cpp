//
// Created by 27682 on 2025/4/15.
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

constexpr int N = 2e5 + 10;
bool f[N];
bitset<N> dp;
int a[N];
ll sum[N];

inline void Zlin() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        dp |= dp << a[i];
        f[i] = dp[i];
        dp[i] = 0;
    }
    for (int i = n + 1; i <= n * 2; i++) {
        f[i] = dp[i];
        sum[i] = sum[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n * 2; i++) {
        if (f[i]) {
            ans = max(ans, sum[i] - i + 1);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
