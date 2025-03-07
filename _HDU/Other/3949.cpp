//
// Created by Zlin on 2024/9/9.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 1e5 + 5;
ll n, k, q, qq;
ll a[N];

inline void gauss() {
    for (int i = 63; ~i && k <= n; i--) {
        for (int j = k; j <= n; j++)
            if (a[j] & (1ll << i)) {
                swap(a[j], a[k]);
                break;
            }
        if (!(a[k] & (1ll << i))) continue;
        for (int j = 1; j <= n; j++)
            if (j != k && (a[j] & (1ll << i))) a[j] ^= a[k];
        ++k;
    }
}

inline ll query() {
    if (k != n + 1) --qq;
    if (qq > (1ll << (k - 1)) - 1) return -1;
    ll ans = 0;
    for (int i = 1; i < k; i++) if (qq & (1ll << (k - i - 1))) ans ^= a[i];
    return ans;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    k = 1;
    gauss();
    cin >> q;
    while (q--) {
        cin >> qq;
        cout << query() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    for (int i = 1; i <= ttt; i++) {
        cout << "Case #" << i << ":\n";
        Zlin();
    }
}