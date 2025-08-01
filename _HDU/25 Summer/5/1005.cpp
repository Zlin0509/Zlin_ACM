//
// Created by Zlin on 2025/8/1.
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

int a, b, c, d;
vi v[4];

inline void Zlin() {
    cin >> a >> b >> c >> d;
    for (int i = 0, k; i < 4; i++) {
        cin >> k;
        v[i].assign(k, 0);
        for (int &it: v[i]) cin >> it;
        sort(v[i].begin(), v[i].end(), greater());
        for (int j = 1; j < k; j++) v[i][j] += v[i][j - 1];
    }
    ll ans = 0;
    for (int dx = 0, ax; dx <= d; dx++) {
        for (int cx = 0; cx <= c; cx++) {
            for (int bx = 0; bx <= b + (d - dx) * 2 + (c - cx); bx++) {
                ax = a + c - cx + (b + (d - dx) * 2 + (c - cx) - bx) * 2;
                ll res = 0;
                int as, bs, cs, ds;
                as = min({ax, (int) v[0].size()});
                bs = min({bx, (int) v[1].size()});
                cs = min({cx, (int) v[2].size()});
                ds = min({dx, (int) v[3].size()});
                if (as) res += v[0][as - 1];
                if (bs) res += v[1][bs - 1];
                if (cs) res += v[2][cs - 1];
                if (ds) res += v[3][ds - 1];
                ans = max(ans, res);
            }
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
