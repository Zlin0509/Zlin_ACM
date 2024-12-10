//
// Created by Zlin on 2024/11/28.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, q;
    cin >> n;
    vll a(n + 1), dep(n + 1);
    vll sum(n + 1), b(n + 1), c(n + 1), cc(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
        sum[i] = sum[i - 1] + b[i];
        dep[i] = dep[i - 1] + n + 1 - i;
        c[1] += b[i];
    }
    for (int i = 2; i <= n; i++) {
        c[i] = c[i - 1] - a[i - 1] * (n - i + 2);
        cc[i] = cc[i - 1] + c[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ll l, r;
        cin >> l >> r;
        int lx = lower_bound(dep.begin(), dep.end(), l) - dep.begin() - 1,
                rx = lower_bound(dep.begin(), dep.end(), r) - dep.begin() - 1;
        ll ans = 0;
        l -= dep[lx] - lx, r -= dep[rx] - rx;
        if (lx == rx) {
            ans = sum[r] - sum[l - 1] - (r - l + 1) * b[lx];
        } else {
            ans += sum[n] - sum[l - 1] - (n - l + 1) * b[lx];
            ans += sum[r] - sum[rx] - (r - rx) * b[rx];
            ans += cc[rx] - cc[lx + 1];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}