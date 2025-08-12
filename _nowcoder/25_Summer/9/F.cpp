//
// Created by Zlin on 2025/8/12.
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

ll cal(int sx1, int sy1, int sx2, int sy2, int tx1, int ty1, int tx2, int ty2) {
    ll res = 1ll * max(abs(sx1 - tx1), abs(sy1 - ty1)) * 2;
    if (abs(sx1 - sx2) != abs(tx1 - tx2)) res += 1;
    else {
        if (sx1 == sx2 && sy1 - sy2 != ty1 - ty2) res += 2;
        if (sy1 == sy2 && sx1 - sx2 != tx1 - tx2) res += 2;
    }
    return res;
}

int sx[2], sy[2], tx[2], ty[2];

inline void Zlin() {
    cin >> sx[0] >> sy[0] >> sx[1] >> sy[1] >> tx[0] >> ty[0] >> tx[1] >> ty[1];
    ll ans = 1e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, cal(sx[i], sy[i], sx[i ^ 1], sy[i ^ 1], tx[j], ty[j], tx[j ^ 1], ty[j ^ 1]));
        }
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
