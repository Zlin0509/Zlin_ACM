//
// Created by Zlin on 2024/9/13.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, k;
    int l = 1, r = 1, mid;
    cin >> n >> k;
    vi a(n + 1), b(n + 1), dp(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], r = max(r, a[i]);
    auto check = [&](int x) {
        for (int i = 0; i < n; i++) a[i] >= x ? b[i] = 1 : b[i] = -1;
        dp[0] = b[0];
        for (int i = 1; i < n; i++) {
            if (i % k == 0) dp[i] = max(dp[i - k], b[i]);
            else {
                dp[i] = dp[i - 1] + b[i];
                if (i >= k) dp[i] = max(dp[i], dp[i - k]);
            }
        }
        return dp[n - 1] > 0;
    };
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}