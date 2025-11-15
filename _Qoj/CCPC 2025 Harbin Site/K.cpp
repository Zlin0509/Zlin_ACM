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

int ans[5005];

inline void Zlin() {
    int W;
    cin >> W;
    cout << W << endl;
    for (int i = 1; i <= W; i++) cout << i << " \n"[i == W];
    ans[1] = W, ans[2] = W + 1;
    for (int i = 3; i <= W; i++) ans[i] = ans[i - 1] + ans[1] + 1;
    for (int i = 1; i <= W; i++) cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
