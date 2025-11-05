//
// Created by 27682 on 2025/11/5.
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

constexpr ll INF = 1e16;
constexpr int N = 2520;

int n, a[10], b[10];
ll m, dp[N][N];

inline void dfs(int x, int t, int s) {
    if (x % a[(t + s) % n] == b[(t + s) % n]) return;
    if (x == 10) dp[s][(s + t) % n] = min(dp[s][(s + t) % n], (ll) t);
    dfs(x, t + 1, s);
    dfs(x + 1, t + 1, s);
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
