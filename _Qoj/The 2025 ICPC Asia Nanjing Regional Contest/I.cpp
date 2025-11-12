//
// Created by Zlin on 2025/11/12.
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

constexpr int N = 2005, M = 5005;

int n, m, a[N], b[N], c[N], d[N], e[N], p[N], vis[N][M];
db dp[N][M];

inline void dij() {

}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p[i];
    
}


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
