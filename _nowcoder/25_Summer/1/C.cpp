//
// Created by 27682 on 2025/7/15.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q, d;
ll a[1010], sum[1010], w[1010], ans[1010];

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + abs(a[i] - a[i + 1]) * w[i];
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            ll res = sum[r - 1] - sum[l - 1];
            if (r != 1) res += w[l - 1] * abs(l - a[l]);
            if (r != n) res += w[r] * abs(r - a[r]);
            ans[r - l] = max(ans[r - l], res);
            if (r - l == 2) {
                cout << res << endl;
            }
        }
    }
    while (q--) {
        cin >> d;
        cout << ans[d] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
