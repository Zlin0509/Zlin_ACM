//
// Created by Zlin on 2025/11/7.
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

constexpr int N = 19;
constexpr ll mo = 998244353;

ll n, a[N];
ll ans[N][N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ans[i][j] = (a[i] + (i == j)) % mo;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cout << ans[i][j] << " \n"[j == n];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
