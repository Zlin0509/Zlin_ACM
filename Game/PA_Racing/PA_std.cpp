//
// Created by Zlin on 2025/5/1.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef long long ll;

int n;
ll a1, b1, a2, b2;

ll cost(ll a, ll b, ll k) {
    return a * k * (k + 1) / 2 + b * k;
}

ll total_cost(ll x) {
    ll y = n - x;
    return cost(a1, b1, x) + cost(a2, b2, y);
}

inline void Zlin() {
    cin >> n >> a1 >> b1 >> a2 >> b2;
    int l = 1, r = n - 1;
    while (r - l > 3) {
        int midl = l + (r - l) / 3;
        int midr = r - (r - l) / 3;
        if (total_cost(midl) < total_cost(midr))
            r = midr - 1;
        else
            l = midl + 1;
    }
    ll ans = 2e18;
    for (int i = l; i <= r; i++) ans = min(ans, total_cost(i));
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
