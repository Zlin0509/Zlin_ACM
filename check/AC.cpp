//
// Created by 27682 on 2025/7/21.
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

int n;
ll a[55], ans;

inline void dfs(int idx, ll val) {
    ans = max({ans, val, val ^ a[idx]});
    if (idx < n) dfs(idx + 1, val);
    for (int i = idx + 2; i <= n; i++) {
        dfs(i, val);
        dfs(i, val ^ a[idx]);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = 0;
    dfs(1, 0ll);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
