//
// Created by Zlin on 2025/8/4.
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

constexpr int N = 2e5 + 10;

int n, p[N], nxt[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i], nxt[i] = 0;
    int ans = n;
    for (int i = 1, tmp, res; i <= n; i++) {
        tmp = p[i];
        if (!nxt[tmp - 1]) nxt[tmp] = tmp;
        else nxt[tmp] = nxt[tmp - 1];
        res = tmp - nxt[tmp];
        if (tmp == n || nxt[tmp] == 1) {
            res = n - res + 1;
        } else {
            res = n - res + 2;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
