//
// Created by Zlin on 2025/9/29.
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

int ans[N], a[N][N];
int n, m;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= max(n, m); i++) ans[i] = 1e7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            ans[i] = min(ans[i], x);
            ans[j] = min(ans[j], x);
        }
    }
    ll res = 0;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
